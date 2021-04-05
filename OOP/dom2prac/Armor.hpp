#pragma once 

#include<vector>
#include<string>

enum TypeA {
	unknown,
	cloth_a,
	leather,
	mail
};

//enum Effect {
//	thoughness = 10,
//	shining = 2,
//	protection = 15,
//	durability = 5
//};


class Armor
{
public:

	Armor(const TypeA type = unknown, const unsigned int defence = 0);
	bool operator==(const Armor&) const;
	bool operator!=(const Armor&) const;

	bool addEffect(const std::string, const int);
	bool removeEffect(const std::string);

	void setType(const TypeA);
	void setDefence(const unsigned int);

	unsigned int getGearscore() const;


private:

	TypeA type;
	unsigned int defence;
	std::vector<std::string> Effects_name;
	std::vector<unsigned int> Effects_power;
	unsigned int gearscore;

	void setGearscore();
};