/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Lubomir Stoykov
* @idnumber 62569
* @task 5
* @compiler VC
*
*/

#include<iostream>
#include<fstream>
using namespace std;

int strSize(char* string) {
	int i = 0;
	while (string[i] != '\0') {
		i++;
	}
	return i;
}

int main() {
	char FindLowest(char*, int);
	char secret(char*, int, char);
	const size_t maxsize = 151;
	char Input[maxsize] = "";
	char Output[1001] = "";
	fstream myFile;
	int size = 0, out = 0;
	myFile.open("message.txt", fstream::in);
	if (myFile.is_open() == false) {
		cout << "-2" << endl;
		return 0;
	}
	do {
		myFile >> Input;
		size = strSize(Input);
		if (size == 0)break;
		for (int i = 0; i < size; i++) {
			if (Input[i] < 'A' || (Input[i] > 'Z' && Input[i] < 'a') || Input[i]>'z') {
				cout<< "-1" << endl;
				return 0;
			}
		}
		char lowest, SecretSymbol;
		lowest = FindLowest(Input, size);
		SecretSymbol = secret(Input, size, lowest);
		Output[out] = SecretSymbol;
		out++;
		for (int i = 0; i < size; i++) {
			Input[i] = '\0';
		}
	} while (true);
	cout << Output << endl;
	myFile.close();
	return 0;
}

char FindLowest(char* string, int size) {
	char tmp = 'z';
	for (int i = 0; i < size; i++) {
		if (tmp > string[i]) {
			tmp = string[i];
		}
	}
	return tmp;
}

char secret(char* string, int size, char lowest) {
	char tmp = lowest + 1;
	if (tmp > 'Z' && tmp < 'a') {
		tmp = 'a';
	}
	if (tmp > 'z') {
		tmp = 'z';
	}
	for (int i = 0; i < size; i++) {
		if (tmp == string[i]) {
			tmp++;
			i = -1;
		}
	}
	return tmp;
}