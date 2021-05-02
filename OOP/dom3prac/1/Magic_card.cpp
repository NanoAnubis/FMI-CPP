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


#include"Magic_card.hpp"


MagicCard::MagicCard(const std::string& _name, const std::string& _effect, const Type& _type)	
	: Card(_name, _effect)
{
	setType(_type);
}

Type MagicCard::getType() const
{
	return type;
}

void MagicCard::setType(const Type& _type)
{
	type = _type;
}
