/**
* Solution to homework assignment 4
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


void Duelist::display()
{
	std::cout << deck.getDeckname() << '|'
		<< deck.countAllCards() << '|'
		<< deck.countMonsterCards() << '|'
		<< deck.countMagicCards() << '|'
		<< deck.countPendulumCards() << std::endl;

	for (size_t i = 0; i < deck.countAllCards(); i++) {
		if (deck.getCard(i)->getCategory() == Card::category::monster) {
			deck.getCard(i)->print();
		}
	}
	for (size_t i = 0; i < deck.countAllCards(); i++) {
		if (deck.getCard(i)->getCategory() == Card::category::magic) {
			deck.getCard(i)->print();
		}
	}
	for (size_t i = 0; i < deck.countAllCards(); i++) {
		if (deck.getCard(i)->getCategory() == Card::category::pendulum) {
			deck.getCard(i)->print();
		}
	}
}

bool Duelist::saveDeck(const std::string& filename)
{
	std::fstream file(filename, std::ios::out | std::ios::trunc);
	if (!file.is_open()) {
		return false;
	}

	file << deck.getDeckname() << '|'
		<< deck.countAllCards() << '|'
		<< deck.countMonsterCards() << '|'
		<< deck.countMagicCards() << '|'
		<< deck.countPendulumCards() << std::endl;

	for (size_t i = 0; i < deck.countAllCards(); i++) {
		if (deck.getCard(i)->getCategory() == Card::category::monster) {
			file << deck.getCard(i)->stringOutput().str();
		}
	}
	for (size_t i = 0; i < deck.countAllCards(); i++) {
		if (deck.getCard(i)->getCategory() == Card::category::magic) {
			file << deck.getCard(i)->stringOutput().str();
		}
	}
	for (size_t i = 0; i < deck.countAllCards(); i++) {
		if (deck.getCard(i)->getCategory() == Card::category::pendulum) {
			file << deck.getCard(i)->stringOutput().str();
		}
	}

	/*for (int i = 0; i < deck.getMonsterCount(); i++) {
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
	}*/
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

	deck.clear();

	std::getline(file, tmp, '|');
	deck.setDeckname(tmp);
	std::getline(file, tmp, '|');
	std::getline(file, tmp, '|');
	sizemonster = std::stoi(tmp);
	std::getline(file, tmp, '|');
	sizemagic = std::stoi(tmp);
	std::getline(file, tmp, '\n');
	sizependulum = std::stoi(tmp);

	for (unsigned int i = 0; i < sizemonster; i++) {
		MonsterCard tmpcard;

		std::getline(file, tmp, '|');		
		tmpcard.setName(tmp);
		std::getline(file, tmp, '|');		
		tmpcard.setEffect(tmp);
		std::getline(file, tmp, '|');		
		tmpcard.setRarity(std::stoi(tmp));
		std::getline(file, tmp, '|');		
		tmpcard.setAttack(std::stoi(tmp));	
		std::getline(file, tmp, '\n');		
		tmpcard.setDefence(std::stoi(tmp));

		deck.addCard(&tmpcard);
	}
	for (unsigned int i = 0; i < sizemagic; i++) {
		MagicCard tmpcard;

		std::getline(file, tmp, '|');
		tmpcard.setName(tmp);
		std::getline(file, tmp, '|');
		tmpcard.setEffect(tmp);
		std::getline(file, tmp, '|');
		tmpcard.setRarity(std::stoi(tmp));
		std::getline(file, tmp, '\n');
		tmpcard.setType(stoEnum(tmp));

		deck.addCard(&tmpcard);
	}
	for (unsigned int i = 0; i < sizependulum; i++) {
		PendulumCard tmpcard;

		std::getline(file, tmp, '|');
		tmpcard.setName(tmp);
		std::getline(file, tmp, '|');
		tmpcard.setEffect(tmp);
		std::getline(file, tmp, '|');
		tmpcard.setRarity(std::stoi(tmp));
		std::getline(file, tmp, '|');
		tmpcard.setAttack(std::stoi(tmp));
		std::getline(file, tmp, '|');
		tmpcard.setDefence(std::stoi(tmp));
		std::getline(file, tmp, '|');
		tmpcard.setScale(std::stoi(tmp));
		std::getline(file, tmp, '\n');
		tmpcard.setType(stoEnum(tmp));

		deck.addCard(&tmpcard);
	}

	file.close();
	return true;
}

bool Duelist::duel(Duelist& other)
{
	if (this == &other) return false;
	if (this->deck.countAllCards() != other.deck.countAllCards()) return false;
	this->deck.shuffle();
	other.deck.shuffle();
	unsigned points_lhs = 0;
	unsigned points_rhs = 0;

	for (size_t i = 0; i < deck.countAllCards(); i++) {
		if (deck.getCard(i) < other.deck.getCard(i)) points_rhs++;
		else if (deck.getCard(i) > other.deck.getCard(i)) points_lhs++;
	}

	if (points_lhs > points_rhs) {
		std::cout << "Duelist " << this->getName() << " wins!" << std::endl;
	}
	else if (points_lhs < points_rhs) {
		std::cout << "Duelist " << other.getName() << " wins!" << std::endl;
	}
	else {
		std::cout << "The duel is a draw!" << std::endl;
	}

	return true;
}
