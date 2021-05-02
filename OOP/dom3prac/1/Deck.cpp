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

#include "Deck.hpp"

Deck::Deck()
{
	setDeckname("unknown");
}

std::string Deck::getDeckname()
{
	return deck_name;
}
int Deck::getMonsterCount() const
{
	return deck_monster.size();
}
int Deck::getMagicCount() const
{
	return deck_magic.size();
}
int Deck::getPendulumCount() const
{
	return deck_pendulum.size();
}

std::vector<MonsterCard>& Deck::getMonsterDeck()
{
	return deck_monster;
}
std::vector<MagicCard>& Deck::getMagicDeck()
{
	return deck_magic;
}
std::vector<PendulumCard>& Deck::getPendulumDeck()
{
	return deck_pendulum;
}


void Deck::setDeckname(const std::string& name)
{
	deck_name = name;
}
void Deck::addMonster(const MonsterCard& card)
{
	deck_monster.push_back(card);
}
void Deck::addMagic(const MagicCard& card)
{
	deck_magic.push_back(card);
}
void Deck::addPendulum(const PendulumCard& card)
{
	deck_pendulum.push_back(card);
}

bool Deck::changeMonster(const unsigned int index, const MonsterCard card)
{
	if (index < deck_monster.size()) {
		deck_monster[index] = card;
		return true;
	}
	else {
		std::cout << "Unexistent index!" << std::endl;
		return false;
	}
}
bool Deck::changeMagic(const unsigned int index, const MagicCard card)
{
	if (index < deck_magic.size()) {
		deck_magic[index] = card;
		return true;
	}
	else {
		std::cout << "Unexistent index!" << std::endl;
		return false;
	}
}
bool Deck::changePendulum(const unsigned int index, const PendulumCard card)
{
	if (index < deck_pendulum.size()) {
		deck_pendulum[index] = card;
		return true;
	}
	else {
		std::cout << "Unexistent index!" << std::endl;
		return false;
	}
}

void Deck::ClearDeck()
{
	deck_monster.clear();
	deck_monster.shrink_to_fit();
	deck_magic.clear();
	deck_magic.shrink_to_fit();
	deck_pendulum.clear();
	deck_pendulum.shrink_to_fit();

}
