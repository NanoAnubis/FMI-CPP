/**
* Solution to homework assignment 2
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021 *
* @author Lubomir Stoykov
* @idnumber 62569
* @task 1
* @compiler VC
*/


//holds all used libraries and 

#pragma once
#pragma warning(disable:26812)

#include<iostream>
#include<vector>
#include<string>



enum Type {
	gold = 0,
	silver = 1,
	essence = 0,
	herbs = 1,
	ores = 2,
	cloth = 3
};

enum TypeAW {
	unknown,
	one_handed = 1,
	two_handed = 2,
	cloth_a,
	leather,
	mail
};

enum WeaponCategory { 
	//numbers specify type requirements : negative have no requirements, positive have by the first digit
	unknown_cat,
	axe = -1,
	sword = -2,
	dagger = 11,
	mace = -3,
	staff = 21,
	spear = -4,
	bow = 22,
	crossbow = 23,
	lance = -5
};

