#include<iostream>
using namespace std;

int main() {
	const size_t SizeText = 151;
	char text[SizeText] = "";
	bool Check(char arr[]);
	cin.getline(text,SizeText);
	cout << Check(text) << endl;
	return 0;
}

bool Check(char arr[]) {
	int counter = 0, counter_tmp = 1, counter_tmp2 = 0;
	char tmp ='\0';
	bool flag = 0;
	const size_t SizeText = 151;
	char checkdS[SizeText] = "";
	size_t size = 0, sizetmp = 0;
	while (arr[size] != '\0') {
		size++;
	}
	for (size_t i = 0; i < size; i++) {
		sizetmp = 0;
		while (checkdS[sizetmp] != '\0') {
			sizetmp++;
		}
		bool isThere = 0;
		for (size_t q = 0; q < sizetmp; q++) {
			if (arr[i] == checkdS[q]) {
				//i++;
				isThere = 1;
			}
		}
		if (isThere == 1) {
			continue;
		}
		else {
			checkdS[sizetmp] = arr[i];
			checkdS[sizetmp + 1] = '\0';
		}

		tmp = arr[i];
		size_t p = 0;
		for (p = i + 1; p < size; p++) {
			if (tmp == arr[p]) {
				counter_tmp++;
			}
		}
		if (counter == 0) {
			counter = counter_tmp;
			counter_tmp = 1;
			flag = 1;
			continue;
		}
		if (counter + counter_tmp == size && sizetmp == 1) { //ako stigne kraq na stringa da prikluchi direktno
			if (counter == 1 && counter_tmp != 1 || counter != 1 && counter_tmp == 1) return 1;
			else if (counter < counter_tmp) {
				if (counter != counter_tmp && counter != counter_tmp - 1) {
					return 0;
				}
			}
			else if (counter > counter_tmp) {
				if (counter != counter_tmp && counter - 1 != counter_tmp) {
					return 0;
				}
			}
		}
		if (counter == 1 && counter_tmp == counter_tmp2 && counter_tmp != 1) {//ako ima 1ca pri drugi (ex. aaaabcccc)
			counter_tmp = 1;
			continue;
		}
		if (counter_tmp == 1 && counter == counter_tmp2 && counter_tmp2 != 1) {
			counter_tmp = 1;
			continue;
		}
		if (counter_tmp2 == 1 && counter_tmp == counter && counter != 1) {
			counter_tmp = 1;
			continue;
		}
		if(sizetmp>1){
			if (counter != counter_tmp && counter_tmp != counter_tmp2) return 0;
			if (counter < counter_tmp) {
				if (counter != counter_tmp && counter != counter_tmp - 1) {
					return 0;
				}
			}
			else if (counter > counter_tmp) {
				if (counter != counter_tmp && counter - 1 != counter_tmp) {
					return 0;
				}
			}
			}
		if (flag == 1) {
			counter_tmp2 = counter_tmp;
			flag = 0;
		}
		counter_tmp = 1;
	}
	
	return 1;
}