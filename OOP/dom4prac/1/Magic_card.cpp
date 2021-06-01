/**
* Solution to homework assignment 4
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Lubomir Stoykov
* @idnumber 62569
* @task 1
* @compiler VC
*/
#pragma once

#include"Magic_card.hpp"


MagicCard::MagicCard(const std::string& _name, const std::string& _effect, const unsigned rarity, const Type& _type)
	: Card(_name, _effect, rarity)
{
	setType(_type);
	CATEGORY = magic;
}

Type MagicCard::getType() const
{
	return type;
}

void MagicCard::setType(const Type& _type)
{
	type = _type;
}

std::string Enumts(const Type type) {
	switch (type)
	{
	case 1: return "trap";
	case 2: return "buff";
	case 3: return "spell";
	default:
		return "unknown";
	}
}


std::ostringstream MagicCard::stringOutput() const
{
	std::ostringstream s;
	s << this->getName() << "|" << this->getEffect() << "|" << this->getRarity()
		<< "|" << Enumts(this->getType()) << std::endl;
	return s;
}


//void MagicCard::print() const
//{
//	std::cout << this->stringOutput().str();
//}

Card* MagicCard::copy() const
{
	return new MagicCard(*this);
}