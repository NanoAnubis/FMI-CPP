/**
* Solution to homework assignment 3
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Lubomir Stoykov
* @idnumber 62569
* @task 1
* @compiler VC
*/


#include"Duelist.hpp"

Duelist::Duelist(const std::string& name)
{
	setName(name);
}

Deck& Duelist::getDeck()
{
	return deck;
}
std::string Duelist::getName() const
{
	return name;
}

void Duelist::setName(const std::string& newname)
{
	name = newname;
}

std::string Enumts(const Type type) {
	switch (type)
	{
	case 1: return "trap";
	case 2: return "buff";
	case 3: return "spell";
	default:
		return "unknown";
	}
}

void Duelist::display()
{
	std::cout << deck.getDeckname() << '|'
		<< deck.getMonsterCount() << '|'
		<< deck.getMagicCount() << '|'
		<< deck.getPendulumCount() << std::endl;

	for (int i = 0; i < deck.getMonsterCount(); i++) {
		std::cout << deck.getMonsterDeck()[i].getName() << '|'
			<< deck.getMonsterDeck()[i].getEffect() << '|'
			<< deck.getMonsterDeck()[i].getAttack() << '|'
			<< deck.getMonsterDeck()[i].getDefence() << std::endl;
	}
	for (int i = 0; i < deck.getMagicCount(); i++) {
		std::cout << deck.getMagicDeck()[i].getName() << '|'
			<< deck.getMagicDeck()[i].getEffect() << '|'
			<< Enumts(deck.getMagicDeck()[i].getType()) << std::endl;
	}
	for (int i = 0; i < deck.getPendulumCount(); i++) {
		std::cout << deck.getPendulumDeck()[i].getName() << '|'
			<< deck.getPendulumDeck()[i].getEffect() << '|'
			<< deck.getPendulumDeck()[i].getAttack() << '|'
			<< deck.getPendulumDeck()[i].getDefence() << '|'
			<< deck.getPendulumDeck()[i].getScale() << '|'
			<< Enumts(deck.getPendulumDeck()[i].getType()) << std::endl;
	}
}

bool Duelist::saveDeck(const std::string& filename)
{
	std::fstream file(filename, std::ios::out | std::ios::trunc);
	if (!file.is_open()) {
		return false;
	}

	file << deck.getDeckname() << '|'
		<< deck.getMonsterCount() << '|'
		<< deck.getMagicCount() << '|'
		<< deck.getPendulumCount() << std::endl;

	for (int i = 0; i < deck.getMonsterCount(); i++) {
		file << deck.getMonsterDeck()[i].getName() << '|'
			<< deck.getMonsterDeck()[i].getEffect() << '|'
			<< deck.getMonsterDeck()[i].getAttack() << '|'
			<< deck.getMonsterDeck()[i].getDefence() << std::endl;
	}
	for (int i = 0; i < deck.getMagicCount(); i++) {
		file << deck.getMagicDeck()[i].getName() << '|'
			<< deck.getMagicDeck()[i].getEffect() << '|'
			<< Enumts(deck.getMagicDeck()[i].getType()) << std::endl;
	}
	for (int i = 0; i < deck.getPendulumCount(); i++) {
		file << deck.getPendulumDeck()[i].getName() << '|'
			<< deck.getPendulumDeck()[i].getEffect() << '|'
			<< deck.getPendulumDeck()[i].getAttack() << '|'
			<< deck.getPendulumDeck()[i].getDefence() << '|'
			<< deck.getPendulumDeck()[i].getScale() <<'|'
			<< Enumts(deck.getPendulumDeck()[i].getType()) << std::endl;
	}
	file.close();
	return true;
}

Type stoEnum(std::string type) {
	if (type == "trap") {
		return trap;
	}
	if (type == "buff") {
		return buff;
	}
	if (type == "spell") {
		return spell;
	}
	return unknown;
}

bool Duelist::loadDeck(const std::string& filename)
{
	std::stringstream tmpstream;
	std::string tmp;
	unsigned int sizemonster = 0;
	unsigned int sizemagic = 0;
	unsigned int sizependulum = 0;

	std::fstream file(filename, std::ios::in);
	if (!file.is_open()) {
		return false;
	}

	deck.ClearDeck();

	std::getline(file, tmp, '|');
	deck.setDeckname(tmp);					//deck name
	std::getline(file, tmp, '|');
	sizemonster = std::stoi(tmp);
	std::getline(file, tmp, '|');
	sizemagic = std::stoi(tmp);
	std::getline(file, tmp, '\n');
	sizependulum = std::stoi(tmp);

	for (unsigned int i = 0; i < sizemonster; i++) {
		MonsterCard tmpcard;

		std::getline(file, tmp, '|');		//card name
		tmpcard.setName(tmp);
		std::getline(file, tmp, '|');		//effect name
		tmpcard.setEffect(tmp);
		std::getline(file, tmp, '|');		//attack points
		tmpcard.setAttack(std::stoi(tmp));
		std::getline(file, tmp, '\n');		//deffence points
		tmpcard.setDefence(std::stoi(tmp));

		deck.getMonsterDeck().push_back(tmpcard);
	}
	for (unsigned int i = 0; i < sizemagic; i++) {
		MagicCard tmpcard;

		std::getline(file, tmp, '|');		//card name
		tmpcard.setName(tmp);
		std::getline(file, tmp, '|');		//effect name
		tmpcard.setEffect(tmp);
		std::getline(file, tmp, '\n');		//type
		tmpcard.setType(stoEnum(tmp));

		deck.getMagicDeck().push_back(tmpcard);
	}
	for (unsigned int i = 0; i < sizependulum; i++) {
		PendulumCard tmpcard;

		std::getline(file, tmp, '|');		//card name
		tmpcard.setName(tmp);
		std::getline(file, tmp, '|');		//effect name
		tmpcard.setEffect(tmp);
		std::getline(file, tmp, '|');		//attack points
		tmpcard.setAttack(std::stoi(tmp));
		std::getline(file, tmp, '|');		//deffence points
		tmpcard.setDefence(std::stoi(tmp));
		std::getline(file, tmp, '|');		//scale
		tmpcard.setScale(std::stoi(tmp));
		std::getline(file, tmp, '\n');		//type
		tmpcard.setType(stoEnum(tmp));

		deck.getPendulumDeck().push_back(tmpcard);
	}

	file.close();
	return true;
}


