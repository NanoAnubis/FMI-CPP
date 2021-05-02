#include<iostream>

using namespace std;
#include"Duelist.hpp"

int main() {

	Duelist p1("Lubo");
	p1.loadDeck("test.txt");
	p1.display();
	p1.saveDeck("test1.txt");

	MonsterCard dragon("Blue-Eyes White Dragon", "This legendary dragon is a powerful engine of destruction.", 3000, 2500); 
	MonsterCard magician("Dark Magician", "The ultimate wizard.", 2500, 2100); 
	MagicCard swords("Swords of Revealing Light", "Your opponent's monsters cannot declare an attack.", spell); 
	MagicCard cylinder("Magic Cylinder", "Inflict damage to your opponent equal to its ATK.", trap); 
	PendulumCard timegazer("Timegazer Magician", "Your opponent cannot activate Trap Magic Cards", 1200, 600,spell , 8); 
	Duelist firstDuelist("Ivan Ivanov"); 
	firstDuelist.getDeck().setDeckname("Magician Deck"); 
	firstDuelist.getDeck().addMonster(dragon); 
	firstDuelist.getDeck().addMagic(swords); 
	firstDuelist.getDeck().addMonster(magician); 
	firstDuelist.getDeck().addMagic(cylinder); 
	firstDuelist.getDeck().addPendulum(timegazer);
	firstDuelist.display();

	return 0;
}