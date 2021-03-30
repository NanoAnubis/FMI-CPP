#pragma once
#include"drink.hpp"

class VendingMachine {
public:
    VendingMachine();
    VendingMachine(const VendingMachine& from);
    VendingMachine& operator=(const VendingMachine& from);

    bool add_drink(const Drink& to_add);
    int buy_drink(const char* drink_name, const double money);

    double get_income() const;

    // Add whatever you deem needed here
    ~VendingMachine();
    int getNumberDrinks() const;
    Drink* getDrinks() const;

    void print() const;

private:
    // Add whatever you deem needed here

    Drink* drinks;
    double income;
    int number_drinks;

    int SearchDrink(const char*) const;
};