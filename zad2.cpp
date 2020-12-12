#include<iostream>
using namespace std;

int strSize(char* string) {
	int i = 0;
	while (string[i] != '\0') {
		i++;
	}
	return i;
}

bool isSmallLatin(char* string) {
	size_t size = strSize(string);
	for (int i = 0; i < size; i++) {
		if (string[i] < 'a' || string[i]>'z') {
			return 0;
		}
	}
	return 1;
}

int main() {
	bool CanColab(char*, char*, char*);
	const size_t size = 150;
	char Text1[size] = "", Text2[size] = "", Colab[size]="";
	cin >> Text1 >> Text2 >> Colab;
	if (isSmallLatin(Text1) == false || isSmallLatin(Text2) == false || isSmallLatin(Colab) == false) {
		cout << "-1" << endl;
		return 0;
	}
	cout << CanColab(Text1, Text2, Colab);
	return 0;
}

bool CanColab(char* first, char* second, char* together) {
	size_t sizeF = strSize(first), sizeS = strSize(second), sizeT = strSize(together);
	bool isTrue = 1;
	if (sizeF + sizeS > sizeT || sizeF + sizeS < sizeT) {
		return 0;
	}
	size_t s = 0;
	char CopyT[150] = "";
	while (together[s] != '\0') {
		CopyT[s] = together[s];
		s++;
	}
	//first + second = firstsecond
	size_t i = 0;	
	while (i < sizeF) {
		for (size_t p = 0; p < sizeF; p++) {
			if (first[i] == together[p]) {
				together[p] = '0';
				break;
			}
		}
		i++;
	}
	i = 0;
	while (i < sizeS) {
		for (size_t p = sizeF; p < sizeT; p++) {
			if (second[i] == together[p]) {
				together[p] = '0';
				break;
			}
		}
		i++;
	}
	s = 0;
	while (together[s] != '\0') {
		if (together[s] != '0') {
			isTrue=0;
		}
		s++;
	}

	if (isTrue == 1) return 1;
	//first + second = secondfirst
	isTrue = 1;
	i = 0;
	while (i < sizeS) {
		for (size_t p = 0; p < sizeS; p++) {
			if (second[i] == CopyT[p]) {
				CopyT[p] = '0';
				break;
			}
		}
		i++;
	}
	i = 0;
	while (i < sizeF) {
		for (size_t p = sizeS; p < sizeT; p++) {
			if (first[i] == CopyT[p]) {
				CopyT[p] = '0';
				break;
			}
		}
		i++;
	}
	s = 0;
	while (CopyT[s] != '\0') {
		if (CopyT[s] != '0') {
			isTrue = 0;
		}
		s++;
	}

	if (isTrue == 1) return 1;

	return 0;
}