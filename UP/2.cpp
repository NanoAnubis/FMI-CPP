#include<iostream>
using namespace std;

double Solve(const char* String) {
	double a, b, c;
	a = String[0]-48;
	b = String[6]-48;
	c = String[10]-48;
	double D = sqrt(b * b - 4 * a * c);
	double x1, x2;
	x1 = (-b + D) / (2 * a);
	x2 = (-b - D) / (2 * a);
	if (x1 > x2) {
		return x1;
	}
	else {
		return x2;
	}
}

int main() {
	char String[14]="";
	cin >> String;
	cout<<Solve(String);
	return 0;
}