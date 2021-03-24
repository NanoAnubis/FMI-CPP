#include<iostream>
#include"VendingMachine.hpp"
using namespace std;

int main() {
	Drink d1{ "Cola", 200,0.5,1.6 };
	Drink d2{ "Fanta", 200,1,2.6 };
	Drink d3 = d1;
	Drink d4{ "AAA",69,6,9 };
	d3 = d4;

	VendingMachine m1;
	cout << m1.add_drink(d1)<<endl;
	cout << m1.add_drink(d2) << endl;
	VendingMachine m2 = m1;
	cout << m2.add_drink(d3) << endl;
	VendingMachine m3;
	m3 = m2;
	cout << m3.add_drink(d4) << endl;
	cout << m1.add_drink(d1) << endl;
	cout << m2.buy_drink("Fanta", 2) << endl;
	cout << m2.buy_drink("Abb", 55) << endl;
	m2.print();
	cout << m2.buy_drink("Fanta", 3) <<endl;
	m2.print();
	cout << m2.get_income() << endl;
	cout << m1.add_drink(d2) << endl;
	cout << m1.buy_drink("Cola", 4) << endl;
	m1.print();
	cout << m1.buy_drink("Fanta", 3) << endl;
	m1.print();
	m3.print();
	return 0;
}