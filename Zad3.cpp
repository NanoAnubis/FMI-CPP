#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int SizeV = 0, number=0, s=0;
	vector<int>seq;
	do {
		cin >> SizeV;
	} while (SizeV < 3 || SizeV>1000);

	for (int i = 0; i < SizeV; i++) {
		cin >> number;
		seq.push_back(number);
		//s = s * 10 + number;
	}
	//cout << s;
	return 0;
}

