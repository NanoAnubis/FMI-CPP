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

#include<string>

class Card {
public:

	Card(const std::string& _name = "Unknown", const std::string& _effect = "Unknown");

	std::string getName() const;
	std::string getEffect() const;

	void setName(const std::string&);
	void setEffect(const std::string&);


protected:
	std::string name;
	std::string effect;
};
