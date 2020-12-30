// Lubomir Stoykov 62569
#include<iostream>
using namespace std;

int podredba(int * arr,int counter=0) {
	if(arr[counter]>arr[counter])
	return;
}

int rec(int num) {
	const int Q = 6174;
	int counter = 0;
	if (num == Q) return counter;
	return rec(num);
}



int main() {
	int number = 0;
	int cifri[4] = {};
	cifri[0] = number / 1000;
	cifri[1] = number / 100 % 10;
	cifri[2] = number / 10 % 10;
	cifri[3] = number % 10;
	cin >> number;
	cout<<rec(number);
	return 0;
}
