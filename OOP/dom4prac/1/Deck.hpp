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

#pragma once

#include"Pendulum_card.hpp"
#include<vector>

class Deck {
public:

	Deck();
	Deck(const Deck&);
	Deck& operator=(const Deck&);
	~Deck();

	std::string getDeckname() const;
	Card* getCard(const unsigned);
	void setDeckname(const std::string&);

	size_t countMagicCards() const;
	size_t countMonsterCards() const;
	size_t countPendulumCards() const;
	size_t countAllCards() const;

	bool addCard(Card*);

	bool changeCard(const unsigned, Card*);
	void clear();
	void shuffle();

private:

	std::string deck_name;
	std::vector<Card*> cards;
	void Copy(const Deck&);
	void Free();
};

