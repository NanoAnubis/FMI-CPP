#include<iostream>
using namespace std;

int strsize(char* arr) {
	int i = 0;
	while (arr[i] != '\0') {
		i++;
	}
	return i;
}

int power(int base, int ex) {
	int result = 1;
	for (int i = 1; i <= ex; i++) {
		result *= base;
	}
	return result;
}

bool isThere(char arr[100][100], char* newarr) {
	int sizenew = strsize(newarr);
	bool check = 0;
	for (int i = 0; i < 100; i++) {
		int sizeprev = strsize(arr[i]);
		if (sizenew == sizeprev) {
			for (int p = 0; p < sizenew; p++) {
				if (newarr[p] == arr[i][p]) {
					check = 1;
				}
				if (newarr[p] != arr[i][p] && check == 1) {
					check = 0;
					break;
				}
				if (newarr[p] != arr[i][p] && check == 0) {
					break;
				}
			}
			if (check == 1) {
				return check;
			}
		}

	}
	return check;
}

int substring(char* arr, const int n) {
	int sizecheck = power(2, n);
	int count = 0, p = 0, q = 0;
	char text[100][100] = {};
	char tmp[100] = "";
	for (int s = 0; s < 100; s++) {
		for (int t = 0; t < 100; t++) {
			text[s][t] = '\0';
		}
	}
	for (int i = 1; i < sizecheck; i++) {
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) { // obhojda vsichko ot 00...01 do 11...11
				//cout << arr[j]<<" ";
				//text[q][p] 
				tmp[p] = arr[j];
				p++;
			}
		}
		if (isThere(text, tmp) == 0) {
			for (int s = 0; s <= p; s++) {
				cout << tmp[s];
				text[q][s] = tmp[s];
				tmp[s] = '\0';
			}
			q++;
			count++;

		}
		else {
			for (int s = 0; i <= p; s++) {
				tmp[s]='\0';
			}
		}
		p = 0;
		cout << endl;
	}
	return count;
}

int main() {
	const size_t maxsize = 100;
	char Input[maxsize]="";
	cin >> Input;
	int size = strsize(Input);
	cout << substring(Input, size);
	return 0;
}
