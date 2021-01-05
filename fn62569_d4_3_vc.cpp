/**
*
* Solution to homework assignment 4
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Lubomir Stoykov
* @idnumber 62569
* @task 3
* @compiler VC
*
*/

#include<iostream>
using namespace std;

int NOD(const int a, const int b) {
	if (a == b) {
		return a;
	}
	if (a > b) {
		return NOD(a - b, b);
	}
	return NOD(a, b - a);
}

void Operation(const int* First, const int* Second, const char op) {
	int Final[2] = {};
	switch (op)
	{
	case '+': {
		Final[0] = First[0] * Second[1] + First[1] * Second[0];
		Final[1] = First[1] * Second[1];
		break;
	}
	case '-': {
		Final[0] = First[0] * Second[1] - First[1] * Second[0];
		Final[1] = First[1] * Second[1];
		break;
	}
	case '*': {
		Final[0] = First[0] * Second[0];
		Final[1] = First[1] * Second[1];
		break;
	}
	case '/': {
		Final[0] = First[0] * Second[1];
		Final[1] = First[1] * Second[0];
		break;
	}
	}
	if (Final[0] == 0) {
		Final[1] = 1;
		cout << Final[0] << " " << Final[1];
		return;
	}
	int chisl = 0, znam = 0;//chislitel,znamenatel
	chisl = Final[0];
	znam = Final[1];
	int nod = NOD(chisl, znam);
	for (int i = 0; i < 2; i++) {
		Final[i] /= nod;
	}
	cout << Final[0] << " " << Final[1] << endl;
	return;
}

int main() {
	int input = 0;
	const int maxsize = 100000000;
	int FirstN[2] = {};
	int SecondN[2] = {};
	char operation = '\0';
	for (int i = 0; i < 2; i++) {
		cin >> input;
		if (input < -maxsize || input > maxsize) {
			cout << "-1" << endl;
			return 0;
		}
		FirstN[i] = input;
	}
	do {
		cin >> operation;
	} while (operation != '+' && operation != '-' && operation != '*' && operation != '/');

	for (int i = 0; i < 2; i++) {
		cin >> input;
		if (input < -maxsize || input > maxsize) {
			cout << "-1" << endl;
			return 0;
		}
		SecondN[i] = input;
	}

	Operation(FirstN, SecondN, operation);

	return 0;
}
