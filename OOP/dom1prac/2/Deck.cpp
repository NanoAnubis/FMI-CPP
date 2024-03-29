/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Lubomir Stoykov
* @idnumber 62569
* @task 2
* @compiler VC
*/

#include "Deck.hpp"

Deck::Deck() {
	for (int i = 0; i < 20; i++) {
		deck_monster[i] = Monster_card();
		deck_magic[i] = Magic_card();
	}
}

int Deck::getMonsterCardCount() const
{
	unsigned int count = 0;
	for (int i = 0; i < 20; i++) {
		if (deck_monster[i].get_isEmpty_monster() == 0) {
			count++;
		}
	}
	return count;
}

int Deck::getMagicCardCount() const
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

void Deck::changeMagicCard(const unsigned int index, const char* _name, const char* _effect, const Type _type)
{
	deck_magic[index].setName(_name);
	deck_magic[index].setEffect(_effect);
	deck_magic[index].setType(_type);
	deck_magic[index].set_isEmpty_magic(false);
}
