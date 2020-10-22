#include<iostream>
using namespace std;
int main()
{
	int n = 0, N = 0, p = 0, m = 0, q = 0; //n - chisloto N koeto moje da se promenq za da ne schupi programata
	int x = 1, y = 1, z = 1; //vremenni stoinosti za m,p,q
	int s=0,T=0; //promenlivi s koito se sravnqva sbora
	cin >> N;
	while (x <= N)
	{
		n = N;
		if (n % x == 0)
		{
			n = n / x;
			int a = 1;
			while (a<=n)
			{
				y = a;
				if (n % y == 0)
				{
					z = n / y;
					s = x + y + z;
					if (s < T || 0 == T)
					{
						m = x;
						p = y;
						q = z;
						T = s;
					}
					
				}
				a++;
			}
		}
		x++;
	}
	cout << m << " " << p << " " << q;
	return 0;
}