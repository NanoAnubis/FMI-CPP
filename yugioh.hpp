#pragma once

class Monster_card {
public:

	Monster_card();
	Monster_card(const char*, const unsigned int, const unsigned int);

private:
	char name[25];
	unsigned int atack_points;
	unsigned int defence_points;
};

enum Type { trap, buff, spell };

class Magic_card {
public:

	Magic_card();
	Magic_card(const char*, const char*, const Type);

private:
	char name[25];
	char effect[100];
	Type type;
};

class Deck {
public:

	int getMonsterCardCount();
	int getMagicCardCount();
	void addMonsterCard(const char*, const unsigned int, const unsigned int);
	void addMagicCard(const char*, const char*, const Type);
	void changeMonsterCard(const unsigned int, const char*, const unsigned int, const unsigned int);
	void changeMagicCard(const unsigned int, const char*, const char*, const Type);

private:
	Monster_card deck_monster[20];
	Magic_card deck_magic[20];

};

class Duelist {
public:

	int getMonsterCardCount_Deck();
	int getMagicCardCount_Deck();
	void addMonsterCard_Deck(const char*, const unsigned int, const unsigned int);
	void addMagicCard_Deck(const char*, const char*, const Type);
	void changeMonsterCard_Deck(const unsigned int, const char*, const unsigned int, const unsigned int);
	void changeMagicCard_Deck(const unsigned int, const char*, const char*, const Type);

private:
	char* name;
	Deck deck;
};
