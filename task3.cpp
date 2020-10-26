#include<iostream>
using namespace std;
int main()
{
	int a = 0, b = 0, c = 0, max = 0, mid = 0, min = 0, palindrom = 0;
	cin >> a >> b >> c;
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
			palindrom = 10001 * max;
		}
		else {
			palindrom = 10001 * mid + 100 * max;
		}
	}
	else {
		palindrom = 10001 * min + 1010 * mid + 100 * max;
	}
	cout << palindrom;
	return 0;
}