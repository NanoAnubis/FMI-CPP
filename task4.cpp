#include<iostream>
using namespace std;
int main()
{
	int n = 0, N = 0, p = 1, m = 1, q = 1, x = 1, y = 1, z = 1;
	int s=0,T=0;
	cin >> N;
	n = N;
	for (int i=1; i <= N; i++)
	{
		n = N;
		int k = i;
		while (k<=n)
		{
			if (n % k == 0)break;
			k++;
		}
		x = k;
		n = n / x;
		int b = k;
		while (b <= n)
		{
			if (n % b == 0)break;
			b++;
		}
		y = b;
		z = n / b;
		s = x + y + z;
		if (s < T || T==0)
		{
			m = x;
			p = y;
			q = z;
		}
		T = s;
	}
	cout << m << " " << p << " " << q;
	return 0;
}