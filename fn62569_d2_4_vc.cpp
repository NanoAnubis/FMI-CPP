/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Lubomir Stoykov
* @idnumber 62569
* @task 4
* @compiler VC
*
*/

#include<iostream>
#include<vector>
using namespace std;
int main()
{
	bool Check(int, int, vector<int>);
	int SumZero(vector<int>);
	int SizeV = 0, number = 0, i = 0;
	vector<int>seq;

	do {
		cin >> SizeV;
	} while (SizeV < 3 || SizeV > 100);

	while (i < SizeV) {
		do {
			cin >> number;
		} while (number < INT_MIN || number > INT_MAX);
		if (Check(i, number, seq) == true) {
			seq.push_back(number);
			i++;
		}
	}

	int s = SumZero(seq);
	cout << s << endl;
	return 0;
}

bool Check(int i, int number, vector<int>seq) {
	for (int k = 0; k < i; k++)
		if (number == seq[k]) {
			return false;
		}
	return true;
}

int SumZero(vector<int>seq) {
	int s = 0, sum = 0, size = seq.size();
	for (int i = 0; i < size - 2; i++) {
		for (int k = i + 1; k < size - 1; k++) {
			for (int p = k + 1; p < size; p++) {
				sum = seq[i] + seq[k] + seq[p];
				if (sum == 0) s++;
			}
		}
	}
	return s;
}