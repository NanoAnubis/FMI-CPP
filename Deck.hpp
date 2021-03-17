#pragma once
#pragma warning(disable : 4996)

#include"Magic_card.hpp"
#include"Monster_card.hpp"

class Deck {
public:

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

