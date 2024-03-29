/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Lubomir Stoykov
* @idnumber 62569
* @task 2
* @compiler VC
*/

#include"Magic_card.hpp"

Magic_card::Magic_card()
{
	setName("Unknown");
	setEffect("Unknown");
	setType(unknown);
	set_isEmpty_magic(true);
}

Magic_card::Magic_card(const char* _name, const char* _effect, const Type _type)
{
	setName(_name);
	setEffect(_effect);
	setType(_type);
	set_isEmpty_magic(false);
}

Magic_card::Magic_card(const Magic_card& other)
{
	setName(other.getName());
	setEffect(other.getEffect());
	setType(other.getType());
	set_isEmpty_magic(other.get_isEmpty_magic());
}

Magic_card& Magic_card::operator=(const Magic_card& other)
{
	if (this != &other) {
		setName(other.getName());
		setEffect(other.getEffect());
		setType(other.getType());
		set_isEmpty_magic(other.get_isEmpty_magic());
	}
	return *this;
}

const char* Magic_card::getName() const
{
	return name;
}

const char* Magic_card::getEffect() const
{
	return effect;
}

Type Magic_card::getType() const
{
	return type;
}

bool Magic_card::get_isEmpty_magic() const
{
	return isEmpty;
}

void Magic_card::setName(const char* _name)
{
	if (strlen(_name) > 25) {
		std::cout << "ERROR : Too big spell name! ->" << _name << std::endl;
		char* newname = new char[26]{ "Error_with_assigning_name" };
		strcpy(name, newname);
		delete[] newname;
	}
	else strcpy(name, _name);
}

void Magic_card::setEffect(const char* _effect)
{
	if (strlen(_effect) > 100) {
		std::cout << "ERROR : Too big effect describtion! ->" << _effect << std::endl;
		char* neweffect = new char[101]{ "Error_with_assigning_effect)" };
		strcpy(name, neweffect);
		delete[] neweffect;
	}
	else strcpy(effect, _effect);
}

void Magic_card::setType(const Type _type)
{
	type = _type;
}

void Magic_card::set_isEmpty_magic(const bool _isEmpty)
{
	isEmpty = _isEmpty;
}
