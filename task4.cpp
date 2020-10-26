#include<iostream>
using namespace std;
int main()
{
	int number = 0, N = 0, p = 0, m = 0, q = 0; //n - chisloto N koeto moje da se promenq za da ne schupi programata
	int x = 1, y = 1, z = 1; //vremenni stoinosti za m,p,q
	int s = 0, T = 0; //promenlivi s koito se sravnqva sbora
	cin >> N;
	while (N < 1 || N>1000000000) {
		cin.clear();
		cin.ignore(100, '\n');
		cin >> N;
	}
	while (x <= N) {
		number = N;
		if (number % x == 0) {
			number = number / x;
			int i = 1;
			while (i <= number) {
				y = i;
				if (number % y == 0) {
					z = number / y;
					s = x + y + z;
					if (s < T || 0 == T) {
						m = x;
						p = y;
						q = z;
						T = s;
					}

				}
				i++;
			}
		}
		x++;
	}
	cout << m << " " << p << " " << q;
	return 0;
}