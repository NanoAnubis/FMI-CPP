#include "yugioh.hpp"
#include <cstring>
#include <iostream>

Monster_card::Monster_card()
{
	setName("Unknown");
	setAttack(0);
	setDefence(0);
	set_isEmpty(true);
}

Monster_card::Monster_card(const char* _name, const unsigned int _attack_points, const unsigned int _defence_points)
{
	setName(_name);
	setAttack(_attack_points);
	setDefence(_defence_points);
	set_isEmpty(false);
}

bool Monster_card::get_isEmpty_monster() 
{
	return isEmpty;
}

void Monster_card::setName(const char* _name)
{
	if (strlen(_name) > 25) {
		std::cout << "ERROR : Too big monster name! ->" << _name << std::endl;
		char* newname = new char[26]{ "Error_with_assigning_name" };
		strcpy_s(name, newname);
		delete[] newname;
	}
	else strcpy_s(name, _name);
}

void Monster_card::setAttack(const unsigned int _attack_points)
{
	attack_points = _attack_points;
}

void Monster_card::setDefence(const unsigned int _defence_points)
{
	defence_points = _defence_points;
}

void Monster_card::set_isEmpty(const bool _isEmpty)
{
	isEmpty = _isEmpty;
}

Magic_card::Magic_card() 
{
	setName("Unknown");
	setEffect("Unknown");
	setType(unknown);
	set_isEmpty_magic(true);
}

Magic_card::Magic_card(const char* _name, const char* _effect, const Type _type)
{
	setName(_name);
	setEffect(_effect);
	setType(_type);
	set_isEmpty_magic(false);
}

bool Magic_card::get_isEmpty_magic()
{
	return isEmpty;
}

void Magic_card::setName(const char* _name)
{
	if (strlen(_name) > 25) {
		std::cout << "ERROR : Too big spell name! ->" << _name << std::endl;
		char* newname = new char[26]{ "Error_with_assigning_name" };
		strcpy_s(name, newname);
		delete[] newname;
	}
	else strcpy_s(name, _name);
}

void Magic_card::setEffect(const char* _effect)
{
	if (strlen(_effect) > 100) {
		std::cout << "ERROR : Too big effect describtion! ->" << _effect << std::endl;
		char* neweffect = new char[101]{ "Error_with_assigning_effect)" };
		strcpy_s(name, neweffect);
		delete[] neweffect;
	}
	else strcpy_s(effect, _effect);
}

void Magic_card::setType(const Type _type)
{
	type = _type;
}

void Magic_card::set_isEmpty_magic(const bool _isEmpty)
{
	isEmpty = _isEmpty;
}

int Deck::getMonsterCardCount()
{
	unsigned int count = 0;
	for (int i = 0; i < 20; i++) {
		if (deck_monster[i].get_isEmpty_monster() == 0) {
			count++;
		}
	}
	return count;
}

int Deck::getMagicCardCount()
{
	unsigned int count = 0;
	for (int i = 0; i < 20; i++) {
		if (deck_magic[i].get_isEmpty_magic() == 0) {
			count++;
		}
	}
	return count;
}

void Deck::addMonsterCard(const char* _name, const unsigned int _attack_points, const unsigned int _defence_points)
{
	unsigned int counter = 0;
	while (deck_monster[counter].get_isEmpty_monster() != 1) {
		counter++;
	}
	changeMonsterCard(counter, _name, _attack_points, _defence_points);
}

void Deck::addMagicCard(const char* _name, const char* _effect, const Type _type)
{
	unsigned int counter = 0;
	while (deck_magic[counter].get_isEmpty_magic() != 1) {
		counter++;
	}
	changeMagicCard(counter, _name, _effect, _type);
}

void Deck::changeMonsterCard(const unsigned int index, const char* _name, const unsigned int _attack_points, const unsigned int _defence_points)
{
	deck_monster[index].setName(_name);
	deck_monster[index].setAttack(_attack_points);
	deck_monster[index].setDefence(_defence_points);
	deck_monster[index].set_isEmpty(false);

}

//trqbva da se kaje za indexite!

void Deck::changeMagicCard(const unsigned int index, const char* _name, const char* _effect, const Type _type)
{
	deck_magic[index].setName(_name);
	deck_magic[index].setEffect(_effect);
	deck_magic[index].setType(_type);
	deck_magic[index].set_isEmpty_magic(false);
}

Duelist::Duelist() {

}

Duelist::Duelist(char*)
{

}

int Duelist::getMonsterCardCount_Deck()
{
	return deck.getMagicCardCount();
}

int Duelist::getMagicCardCount_Deck()
{
	return deck.getMagicCardCount();
}

void Duelist::addMonsterCard_Deck(const char*, const unsigned int, const unsigned int)
{

}

void Duelist::addMagicCard_Deck(const char*, const char*, const Type)
{

}

void Duelist::changeMonsterCard_Deck(const unsigned int, const char*, const unsigned int, const unsigned int)
{

}

void Duelist::changeMagicCard_Deck(const unsigned int, const char*, const char*, const Type)
{

}

