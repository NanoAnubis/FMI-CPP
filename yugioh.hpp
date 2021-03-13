#pragma once

class Monster_card {
public:

	Monster_card();
	Monster_card(const char*, const unsigned int, const unsigned int);
	const char* getName() const;
	int getAttack() const;
	int getDefence() const;
	bool get_isEmpty_monster() const;
	void setName(const char*);
	void setAttack(const unsigned int);
	void setDefence(const unsigned int);
	void set_isEmpty(const bool);



private:
	char name[26];
	unsigned int attack_points;
	unsigned int defence_points;
	bool isEmpty;
};

enum Type { 
	unknown,
	trap,
	buff,
	spell
};

class Magic_card {
public:

	Magic_card();
	Magic_card(const char*, const char*, const Type);
	const char* getName() const;
	const char* getEffect() const;
	Type getType() const;
	bool get_isEmpty_magic() const;
	void setName(const char*);
	void setEffect(const char*);
	void setType(const Type);
	void set_isEmpty_magic(const bool);

private:
	char name[26];
	char effect[101];
	Type type;
	bool isEmpty;
};

class Deck {
public:

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

class Duelist {
public:

	Duelist();
	Duelist(const char*);
	int getMonsterCardCount_Deck() const;
	int getMagicCardCount_Deck() const;
	void addMonsterCard_Deck(const char*, const unsigned int, const unsigned int);
	void addMagicCard_Deck(const char*, const char*, const Type);
	void changeMonsterCard_Deck(const unsigned int, const char*, const unsigned int, const unsigned int);
	void changeMonsterCard_Deck(const unsigned int, const Monster_card&);
	void changeMagicCard_Deck(const unsigned int, const char*, const char*, const Type);
	void changeMagicCard_Deck(const unsigned int, const Magic_card&);
private:
	const char* name;
	Deck deck;
};
