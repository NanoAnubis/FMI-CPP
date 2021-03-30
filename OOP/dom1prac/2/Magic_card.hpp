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

#pragma once
#pragma warning(disable : 4996)
#pragma warning(disable : 26812) //disables warning for 'enum class' instead of just 'enum'

#include <cstring>
#include <iostream>

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
	Magic_card(const Magic_card&);
	Magic_card& operator=(const Magic_card&);
	~Magic_card() {};

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
