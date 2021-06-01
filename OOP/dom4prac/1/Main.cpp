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



#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#else
#define DBG_NEW new
#endif

#include<iostream>

using namespace std;
#include"Duelist.hpp"

int main() {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Duelist p1("Lubo");
	p1.loadDeck("test.txt");
	p1.display();
	p1.getDeck().shuffle();
	p1.getDeck().shuffle();
	p1.getDeck().shuffle();
	p1.getDeck().shuffle();
	p1.display();
	p1.saveDeck("test1.txt");

	MonsterCard dragon("Blue-Eyes White Dragon", "This legendary dragon is a powerful engine of destruction.",13, 3000, 2500); 
	MonsterCard magician("Dark Magician", "The ultimate wizard.",43, 2500, 2100); 
	MagicCard swords("Swords of Revealing Light", "Your opponent's monsters cannot declare an attack.",123, spell); 
	MagicCard cylinder("Magic Cylinder", "Inflict damage to your opponent equal to its ATK.", 4, trap); 
	PendulumCard timegazer("Timegazer Magician", "Your opponent cannot activate Trap Magic Cards",3, 1200, 600, 8, spell); 
	Duelist firstDuelist("Ivan Ivanov"); 

	//swords.print();
	//cout << swords;
	firstDuelist.getDeck().setDeckname("Magician Deck"); 
	firstDuelist.getDeck().addCard(&dragon); 
	firstDuelist.getDeck().addCard(&swords);
	firstDuelist.getDeck().addCard(&magician);
	firstDuelist.getDeck().addCard(&cylinder);
	firstDuelist.getDeck().addCard(&timegazer);
	firstDuelist.getDeck().shuffle();
	cout << firstDuelist.getDeck().changeCard(1, &cylinder) << endl;
	cout << firstDuelist.getDeck().changeCard(1, &dragon) << endl;
	cout << firstDuelist.getDeck().changeCard(1, &timegazer) << endl;
	firstDuelist.display();
	firstDuelist.saveDeck("test1.txt");

	firstDuelist.duel(p1);
	p1.duel(firstDuelist);
	firstDuelist.duel(firstDuelist);

	return 0;

	_CrtDumpMemoryLeaks();
}