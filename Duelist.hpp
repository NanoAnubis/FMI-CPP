#pragma once
#pragma warning(disable : 4996)

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
