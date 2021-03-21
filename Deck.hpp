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

#pragma once

#include"Magic_card.hpp"
#include"Monster_card.hpp"

class Deck {
public:

	Deck();
	~Deck() {};

	int getMonsterCardCount() const;
	int getMagicCardCount() const;

	void addMonsterCard(const char*, const unsigned int, const unsigned int);
	void addMagicCard(const char*, const char*, const Type);
	void changeMonsterCard(const unsigned int, const char*, const unsigned int, const unsigned int);
	void changeMagicCard(const unsigned int, const char*, const char*, const Type);

private:
	Monster_card deck_monster[20];
	Magic_card deck_magic[20];
};

