#include "drink.hpp"

Drink::Drink() : name(nullptr), calories(0), quantity(0), price(0)
{}
Drink::Drink(const char* init_name, const int init_calories, const double& init_quantity, const double& init_price)
	:calories(init_calories), quantity(init_quantity), price(init_price)
{
	set_name(init_name);
}
Drink::Drink(const Drink& other)
{
	set_name(other.get_name());
	calories = other.get_calories();
	quantity = other.get_quantity();
	price = other.get_price();
}
Drink& Drink::operator=(const Drink& other)
{
	if (this != &other)
	{
		set_name(other.get_name());
		calories = other.get_calories();
		quantity = other.get_quantity();
		price = other.get_price();
	}
	return *this;
}
Drink::~Drink()
{
	Free();
}

const char* Drink::get_name() const
{
	return name;
}
int Drink::get_calories() const
{
	return calories;
}
double Drink::get_quantity() const
{
	return quantity;
}
double Drink::get_price() const
{
	return price;
}

void Drink::set_name(const char* new_name)
{
	Free();
	name = new char[strlen(new_name) + 1];
	strcpy(name, new_name);
}


void Drink::Free() 
{
	delete[] name;
}