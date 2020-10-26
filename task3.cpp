#include<iostream>
using namespace std;
int main()
{
	int a = 0, b = 0, c = 0, max = 0, mid = 0, min = 0, palindrom = 0;
	//validation start
	cin >> a;
	while (a < 0 || a>9) {
		cin.clear();
		cin.ignore(100, '\n');
		cin >> a;
	}
	cin >> b;
	while (b < 0 || b>9) {
		cin.clear();
		cin.ignore(100, '\n');
		cin >> b;
	}
	cin >> c;
	while (c < 0 || c>9) {
		cin.clear();
		cin.ignore(100, '\n');
		cin >> c;
	}
	//validation end
	max = a;
	mid = b;
	min = c;
	int buff = 0;
	for (int i = 1; i <= 2; i++) {
		if (max < mid) {
			buff = max;
			max = mid;
			mid = buff;
		}
		if (mid < min) {
			buff = mid;
			mid = min;
			min = buff;
		}
	}
	if (max == mid && mid == min) {
		if (max == 0) {
			palindrom = 0;
		}
		else {
			palindrom = 111 * max;
		}
	}
	else if (min == 0) {
		if (mid == 0) {
			palindrom = 1001 * max;
		}
		else if (max == mid) {
			palindrom = 101 * mid;
		}
		else {
			palindrom = 10001 * mid + 100 * max;
		}
	}
	else if (max == mid) {
		palindrom = 101 * max + 10 * min;
	}
	else if (mid == min) {
		palindrom = 101 * min + 10 * max;
	}
	else {
		palindrom = 10001 * min + 1010 * mid + 100 * max;
	}
	cout << palindrom;
	return 0;
}