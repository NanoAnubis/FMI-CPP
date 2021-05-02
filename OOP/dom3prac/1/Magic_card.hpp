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

#pragma once
#pragma warning(disable : 4996)
#pragma warning(disable : 26812) //disables warning for 'enum class' instead of just 'enum'

#include"Card.hpp"
#include <cstring>
#include <iostream>

enum Type {
	unknown,
	trap,
	buff,
	spell
};

class MagicCard : virtual public Card
{
public:

	MagicCard(const std::string& name = "Unknown", const std::string& effect = "Unknown", const Type& type = unknown);

	Type getType() const;
	void setType(const Type&);

private:

	Type type;
};
