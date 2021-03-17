#include"Duelist.hpp"

Duelist::Duelist()
{
	name = new char[strlen("Unknown") + 1];
	strcpy(name, "Unknown");
	deck = Deck();
}

Duelist::Duelist(const char* _name)
{
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
	deck = Deck();
}

Duelist::~Duelist()
{
	delete[] name;
}

void Duelist::setName(const char* _name)
{
	delete[] name;
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
}

int Duelist::getMonsterCardCount_Deck() const
{
	return deck.getMonsterCardCount();
}

int Duelist::getMagicCardCount_Deck() const
{
	return deck.getMagicCardCount();
}

void Duelist::addMonsterCard_Deck(const char* _name, const unsigned int _attack_points, const unsigned int _defence_points)
{
	deck.addMonsterCard(_name, _attack_points, _defence_points);
}

void Duelist::addMagicCard_Deck(const char* _name, const char* _effect, const Type _type)
{
	deck.addMagicCard(_name, _effect, _type);
}

void Duelist::changeMonsterCard_Deck(const unsigned int index, const char* _name, const unsigned int _attack_points, const unsigned int _defence_points)
{
	deck.changeMonsterCard(index, _name, _attack_points, _defence_points);
}

void Duelist::changeMagicCard_Deck(const unsigned int index, const char* _name, const char* _effect, const Type _type)
{
	deck.changeMagicCard(index, _name, _effect, _type);
}

void Duelist::changeMonsterCard_Deck(const unsigned int index, const Monster_card& newcard)
{
	deck.changeMonsterCard(index, newcard.getName(), newcard.getAttack(), newcard.getDefence());
}

void Duelist::changeMagicCard_Deck(const unsigned int index, const Magic_card& newcard)
{
	deck.changeMagicCard(index, newcard.getName(), newcard.getEffect(), newcard.getType());
}
