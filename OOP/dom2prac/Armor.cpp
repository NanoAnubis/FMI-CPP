#include"Armor.hpp"

Armor::Armor(const TypeA type, const unsigned int defence)
{
	setType(type);
	setDefence(defence);
	//setGearscore();
}

bool Armor::operator==(const Armor& other) const
{
	return gearscore == other.getGearscore();
}
bool Armor::operator!=(const Armor& other) const
{
	return !(gearscore == other.getGearscore());
}

bool Armor::addEffect(const std::string name, const int power)
{
	for (int i = 0; i < Effects_name.size(); i++) {
		if (Effects_name[i] == name) {
			return 0;
		}
	}
	Effects_name.push_back(name);
	Effects_power.push_back(power);
	setGearscore();
	return 1;
}
bool Armor::removeEffect(const std::string name)
{
	for (int i = 0; i < Effects_name.size(); i++) {
		if (Effects_name[i] == name) {
			Effects_name.erase(Effects_name.begin() + i);
			Effects_power.erase(Effects_power.begin() + i);
			setGearscore();
			return 1;
		}
	}
	return 0;
}

void Armor::setType(const TypeA _type)
{
	type = _type;
}
void Armor::setDefence(const unsigned int _defence)
{
	defence = _defence;
}

void Armor::setGearscore()
{
	gearscore = 0;
	for (int i = 0; i < Effects_power.size(); i++) {
		gearscore += Effects_power[i];
	}
}

unsigned int Armor::getGearscore() const
{
	return gearscore;
}