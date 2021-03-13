#include<iostream>
#include "yugioh.hpp"

using namespace std;

int main() {

	Monster_card m1;
	Monster_card m2{ "Exodia",9999,9999 };
	//Monster_card m3{ "ExodiaExodiaExodiaExodiaaa",9999,9999 };
	Magic_card s1;
	Magic_card s2{ "Bind","Binds enemy for 15351 turns.",spell };
	//Magic_card s3{ "ExodiaExodiaExodiaExodiaaa","something", buff };
	Deck d1;
	d1.addMagicCard("Karakachanka", "nikoi ne znae", spell);
	d1.addMonsterCard("Urangutan", 123, 321);
	d1.changeMagicCard(6, "avada kadabra", "insta kill", spell);
	d1.changeMagicCard(10, "mnogo jivot", "dava mnogo jivot", buff);
	d1.changeMonsterCard(3, "obunga", 666, 456);
	d1.changeMonsterCard(7, "aaaaaaaaa", 888, 111);
	cout << d1.getMonsterCardCount() << endl;
	cout << d1.getMagicCardCount() << endl;
	Duelist p1;
	Duelist p2{ "Lubo" };
	p1.addMagicCard_Deck("Karakachanka", "nikoi ne znae", spell);
	p2.addMonsterCard_Deck("Urangutan", 123, 321);
	p1.changeMagicCard_Deck(6, "avada kadabra", "insta kill", spell);
	p2.changeMonsterCard_Deck(3, "obunga", 666, 456);
	p1.changeMonsterCard_Deck(7, "aaaaaaaaa", 888, 111);
	p2.changeMonsterCard_Deck(7, "aaaaaaaaa", 888, 111);

	return 0;
}