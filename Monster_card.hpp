#pragma once
#pragma warning(disable : 4996)

class Monster_card {
public:

	Monster_card();
	Monster_card(const char*, const unsigned int, const unsigned int);
	~Monster_card() {};

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
