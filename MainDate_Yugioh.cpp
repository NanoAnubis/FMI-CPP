#include<iostream>
#include "Duelist.hpp"
#include "Date.hpp"
using namespace std;

int main() {

	Date dt1;
	Date dt2(25, 5, 2011);
	Date dt3 = dt1;
	cout << dt1.isLeapYear() << endl;
	cout << dt2.isLeapYear() << endl;
	cout << dt1.isLaterThen(dt2) << endl;
	cout << dt2.isLaterThen(dt1) << endl;
	dt3 = dt2;
	dt1.addDays(135);
	dt2.removeDays(53);
	dt1.addDays(330);
	dt2.removeDays(500);
	cout << dt1.DaysToXmas() << endl;
	cout << dt1.DaysToNewYear() << endl;
	cout << dt2.DaysToXmas() << endl;
	cout << dt1.DaysToDate(dt2) << endl;
	cout << dt2.DaysToDate(dt1) << endl;

	Monster_card m1;
	Monster_card m2{ "Exodia",9999,9999 };
	//Monster_card m3{ "ExodiaExodiaExodiaExodiaaa",9999,9999 };
	Monster_card m3 = m2;
	m1 = m3;
	Magic_card s1;
	Magic_card s2{ "Bind","Binds enemy for 15351 turns.",spell };
	Magic_card s3 = s2;
	s1 = s3;
	//Magic_card s3{ "ExodiaExodiaExodiaExodiaaa","something", buff };
	Deck d1;
	d1.addMagicCard("asdasdasd", "nikoi ne znae", spell);
	d1.addMonsterCard("Urangutan", 123, 321);
	d1.changeMagicCard(6, "avada kadabra", "insta kill", spell);
	d1.changeMagicCard(10, "mnogo jivot", "dava mnogo jivot", buff);
	d1.changeMonsterCard(3, "oaoaoao", 666, 456);
	d1.changeMonsterCard(7, "aaaaaaaaa", 888, 111);
	cout << d1.getMonsterCardCount() << endl;
	cout << d1.getMagicCardCount() << endl;
	Duelist p1;
	Duelist p2{ "Lubo" };
	p1.addMagicCard_Deck("asdasdasd", "nikoi ne znae", spell);
	p2.addMonsterCard_Deck("Urangutan", 123, 321);
	p1.changeMagicCard_Deck(6, "avada kadabra", "insta kill", spell);
	p2.changeMonsterCard_Deck(3, "oaoaoao", 666, 456);
	p1.changeMonsterCard_Deck(7, "aaaaaaaaa", 888, 111);
	p2.changeMonsterCard_Deck(7, "aaaaaaaaa", 888, 111);
	p2.changeMagicCard_Deck(13, s2);
	p2.changeMonsterCard_Deck(11, m2);
	cout << p1.getMagicCardCount_Deck() << endl;
	cout << p2.getMonsterCardCount_Deck() << endl;
	p1.setName("NotLuboooo");
	
	return 0;
}