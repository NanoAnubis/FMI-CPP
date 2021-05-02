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

#pragma once

#include"Pendulum_card.hpp"
#include<vector>

class Deck {
public:

	Deck();

	std::string getDeckname();
	int getMonsterCount() const;
	int getMagicCount() const;
	int getPendulumCount() const;

	std::vector<MonsterCard>& getMonsterDeck();
	std::vector<MagicCard>& getMagicDeck();
	std::vector<PendulumCard>& getPendulumDeck();

	void setDeckname(const std::string&);
	void addMonster(const MonsterCard&);
	void addMagic(const MagicCard&);
	void addPendulum(const PendulumCard&);

	bool changeMonster(const unsigned int, const MonsterCard);
	bool changeMagic(const unsigned int, const MagicCard) ;
	bool changePendulum(const unsigned int, const PendulumCard);

	void ClearDeck();

private:

	std::string deck_name;
	std::vector<MonsterCard> deck_monster;
	std::vector<MagicCard> deck_magic;
	std::vector<PendulumCard> deck_pendulum;
};

