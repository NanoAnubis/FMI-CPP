#pragma once

#include<vector>
#include<string>

enum TypeW {
	unknown_type,
	one_handed = 1,
	two_handed = 2
};

enum WeaponCategory {
	unknown_cat,
	axe,
	sword,
	dagger,
	mace,
	staff
};


class Weapon
{
public:

	Weapon(const TypeW type = unknown_type, const WeaponCategory category = unknown_cat,
		const unsigned int mindmg = 0, const unsigned int maxdmg = 0);

	void ChangeType(const TypeW);
	void ChangeCategory(const WeaponCategory);
	bool addEffect(const std::string,const int);
	bool removeEffect(const std::string);
	bool ChangePowerOfEffect(const std::string, const int);

private:

	TypeW type;
	WeaponCategory category;
	unsigned int hit_damage[2];
	std::vector<std::string> Effects_name;
	std::vector<unsigned int> Effects_power;
	unsigned int Weaponscore;
};

