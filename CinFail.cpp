#include <iostream>
using namespace std;
int main() {
	int n;
	while (!(cin >> n))
	{
		cin.clear();
		cin.ignore(100, '\n');
	}
	cout << n;
	return 0;
}