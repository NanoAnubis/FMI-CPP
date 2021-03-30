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

#include"Deck.hpp"

class Duelist {
public:

	Duelist();
	Duelist(const char*);
	~Duelist();

	void setName(const char*);

	int getMonsterCardCount_Deck() const;
	int getMagicCardCount_Deck() const;

	void addMonsterCard_Deck(const char*, const unsigned int, const unsigned int);
	void addMagicCard_Deck(const char*, const char*, const Type);
	void changeMonsterCard_Deck(const unsigned int, const char*, const unsigned int, const unsigned int);
	void changeMonsterCard_Deck(const unsigned int, const Monster_card&);
	void changeMagicCard_Deck(const unsigned int, const char*, const char*, const Type);
	void changeMagicCard_Deck(const unsigned int, const Magic_card&);

private:
	char* name;
	Deck deck;
};
