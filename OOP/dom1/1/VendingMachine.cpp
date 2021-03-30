#include "VendingMachine.hpp"

#pragma warning (disable : 6385) // gives false warning so i turned it off


/// MAHNI POSLE!!!
#include<iostream>
using namespace std;
/// 


VendingMachine::VendingMachine() : drinks(nullptr),income(0),number_drinks(0)
{}
VendingMachine::VendingMachine(const VendingMachine& from)
{
	number_drinks = from.getNumberDrinks();
	drinks = new Drink[number_drinks];
	for (int i = 0; i < number_drinks; i++) {
		drinks[i] = from.getDrinks()[i];
	}
	income = from.get_income();

}
VendingMachine& VendingMachine::operator=(const VendingMachine& from)
{
	if (this != &from) {
		number_drinks = from.getNumberDrinks();
		drinks = new Drink[number_drinks];
		for (int i = 0; i < number_drinks; i++) {
			drinks[i] = from.getDrinks()[i];
		}
		income = from.get_income();
	}
	return *this;
}
VendingMachine::~VendingMachine()
{
	delete[] drinks;
}

bool VendingMachine::add_drink(const Drink& to_add)
{
	if (SearchDrink(to_add.get_name()) == -1) { //false
		number_drinks++;
		Drink* new_drinks = new Drink[number_drinks];
		if (number_drinks != 1) {
			for (int i = 0; i < number_drinks - 1; i++) {
				new_drinks[i] = drinks[i];
			}
		}
		new_drinks[number_drinks - 1] = to_add;
		delete[] drinks;
		drinks = new Drink[number_drinks];
		for (int i = 0; i < number_drinks; i++) {
			drinks[i] = new_drinks[i];
		}
		delete[] new_drinks;
		return true;
	}
	return false;
}
int VendingMachine::buy_drink(const char* drink_name, const double money)
{
	int k = SearchDrink(drink_name);
	if (k != -1) {
		if (money >= drinks[k].get_price()) {
			number_drinks--;
			if (number_drinks == 0) {
				income += money;
				delete[] drinks;
				drinks = nullptr;
				return 0;
			}
			Drink* new_drinks = new Drink[number_drinks];
			int p = 0;
			for (int i = 0; i < number_drinks + 1; i++) {
				if (i != k) { 
					new_drinks[p] = drinks[i]; 
					p++;
				}
			}
			delete[] drinks;
			drinks = new Drink[number_drinks];
			for (int i = 0; i < number_drinks; i++) {
				drinks[i] = new_drinks[i];
			}
			delete[] new_drinks;
			income += money;
			return 0;
		}
		income += money;
		return 1;
	}
	return 2;
}

Drink* VendingMachine::getDrinks() const
{
	return drinks;
}
int VendingMachine::getNumberDrinks() const
{
	return number_drinks;
}
double VendingMachine::get_income() const
{
	return income;
}

int VendingMachine::SearchDrink(char const* drink_name) const
{
	for (int i = 0; i < number_drinks; i++) {
		if (strcmp(drinks[i].get_name(), drink_name) == 0) return i;
	}
	return -1;
}

void VendingMachine::print() const
{
	if (number_drinks >= 1) {
		for (int i = 0; i < number_drinks; i++) {
			cout << "Drink: " << drinks[i].get_name() << " has -> calories: " << drinks[i].get_calories()
				<< " quantity: " << drinks[i].get_quantity() << " price: " << drinks[i].get_price() << endl;
		}
	}
	cout << "Income: " << income << endl;
}