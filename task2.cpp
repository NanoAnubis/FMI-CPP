#include<iostream>
using namespace std;
int main()
{
	int n=0,maxc=0,maxp=0;//maxc- nastoqsht maximum, maxp- predishen maximum 
	cin >> n;
	do
	{
		cin >> n;
		if (maxc < n)
		{
			maxp = maxc;
			maxc = n;
		}
	} while (n > 0);
	cout << maxp;
	return 0;
}