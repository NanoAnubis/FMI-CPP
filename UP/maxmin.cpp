#include<iostream>
using namespace std;


void maxmin(int m,int n,int p)
{
	int i = 1, x = 0;
	while (i <= 2) {
		if (m < n) {
			x = m;
			m = n;
			n = x;
		}
		if (n < p) {
			x = n;
			n = p;
			p = x;
		}
		i++;
	}
	cout << m << " " << n << " " << p;
	return;
}

int main()
{
	int a=0,b=0,c=0;
	cin >> a >> b >> c;
	maxmin(a, b, c);
	return 0;
}