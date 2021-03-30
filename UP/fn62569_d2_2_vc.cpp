/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Lubomir Stoykov
* @idnumber 62569
* @task 2
* @compiler VC
*
*/

#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int SizeV = 0;
	vector<double>DShares;
	double share = 0, profit = 0;

	do {
		cin >> SizeV;
	} while (SizeV < 3 || SizeV > 365);

	for (int i = 0; i < SizeV; i++) {
		do {
			cin >> share;
		} while (share < 0.1 || share>100);
		DShares.push_back(share);
	}

	double initP = DShares[0];//cena na kupena akciq v nachaloto
	bool change = true;

	for (int i = 1; i < SizeV; i++) {
		if (DShares[i - 1] > DShares[i]) {
			profit += (DShares[i - 1] - initP);
			initP = DShares[i];
		}
		if (i == SizeV - 1) {
			profit += (DShares[i] - initP);
		}
		else if (initP > DShares[i]) {
			initP = DShares[i];
			}
	}

	cout << profit;
	return 0;
}