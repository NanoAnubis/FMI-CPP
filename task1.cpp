#include<iostream>
using namespace std;
int main()
{
	int n = 0, x = 0, m = 0, total = 0;
	cin >> n >> x >> m;
	for (int i=1; i <= n; i++) {
		if (i % 2 != 0) {
			total += m;
		}
		else {
			total = total + ((i/2) * 30) - 5;
		}
	}
	if (total > x) {
		cout << "yes " << total - x;
	}
	else {
		cout << "no " << x - total;
	}
	return 0;
}