#include<iostream>
using namespace std;
int main()
{
	int a = 0, b = 0, c = 0, mn = 0, mx = 0, s = 0, md = 0;
	cin >> a >> b >> c;
	//trqbva da se promeni ako 0 vliza v cifrite
	mn = min(min(a, b), c);
	mx = max(max(a, b), c);
	//promqna ako min,max sa STL
	md = (a + b + c) - (mx + mn);
	s = mn * 10001 + md * 1010 + mx * 100;
	cout << s;
	return 0;
}