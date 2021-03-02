#include<iostream>
using namespace std;

/*
bool isThere(char* str, char s, int size) {
	for (int i = 0; i < size; i++) {
		if (s == str[i]) {
			return true;
		}
	}
	return false;
}

char* CheckStr(char string[]) {
	int counter = 0, ch = 0;
	char checker = string[ch];
	int i = 1, p = 0, size = 0;
	while (string[size] != '\0') {
		size++;
	}
	char* str1 = new char[size] {};
	while (string[i] != '\0') {
		if (checker == string[i]) {

			if (isThere(str1, checker, size) == false) {
				str1[p] = checker;
				p++;
				str1[p] = '\0';
			}

		}
		i++;
		if (i == size) {
			ch++;
			checker = string[ch];
			i = ch + 1;
		}
	}
	char* str = new char[p] {};
	i = 0;
	while (str1[i] != '\0') {
		str[i] = str1[i];
		i++;
		str[i] = '\0';
	}

	delete[]str1;
	return str;
}

int main() {
	char str[] = "aif8sltt8f";
	CheckStr(str);
	return 0;
}

int * test(int number) {
	int &a = number;
	a *= 10;
	int* point = &a;
	return point;
}

bool doExist(char* symbols, char* word) {
	bool check = true;
	for (int i = 0; symbols[i] != '\0'; i++) {
		check = false;
		for (int p = 0; word[p] != '\0'; p++)
		{
			if (symbols[i + p] == word[p]) {
				check = true;
			}
			else {
				check = false;
				break;
			}

		}
		if (check == true) {
			return check;
		}
	}
	return check;
}

double abs_a(double x) {
	if (x < 0) {
		return -x;
	}
	return x;
}


double sqrt_a(double a, double eps) {
	double x = a, y = a;
	do {
		y = x;
		x = (1.0 / 2) * (y + a / y);
	} while (abs_a(x - y) > eps);

	return x;
}

int main() {
	int* arr;
	char symb[] = "aaaaab sda sa";
	char w[] = "ss";
	cout << doExist(symb, w) << endl;
	double o = 37, p = 0.1;
	cout << sqrt_a(o,p) << endl;
	arr = new int[5]{ 1,2,3,4,5 };
	int** matrix = new int*[5];
	char* string = new char[5]{"abcd"};
	int q = 0;
	while (string[q] != '\0') {
		cout << string[q] << " ";
		q++;
	}
	cout << endl;
	for (int i = 0; i < 5; i++) {
		matrix[i] = new int[5]{ 1 + i,2 + i,3 + i,4 + i,5 + i };
	}
	for (int i = 0; i < 5; i++) {
		for (int p = 0; p < 5; p++) {
			cout << matrix[i][p]<<" ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < 5; i++) {
		cout << *(arr + i) << " ";
	}
	cout << test(123)<<endl;
	int b = 6871, c = 894;
	int* x = &b;
	cout << &b << " " << &c << " " << *x << endl;
	int a[6] = { 0,2,4,6,8,7 };

	for (int i = 0; i < 6; i++) {
		cout << *(a + i) << " ";
	}
	for (int i = 0; i < 5; i++) {
		delete [] matrix[i];
	}
	delete[] matrix;
	delete[]arr;
	delete[]string;
	return 0;
}


void Revert(char str[]) {
	int i = 0;
	while (str[i] != '\0') {
		if (str[i] > 'Z') {
			str[i] -= ('a' - 'A');
		}
		else {
			str[i] += ('a' - 'A');
		}
		i++;
	}
}



bool CheckDate(char date[]) {
	int d = 0, m = 0;

	if (date[5] != '\0') {
		return false;
	}

	d = (date[0] - '0') * 10 + (date[1] - '0');
	m = (date[3] - '0') * 10 + (date[4] - '0');

	if (m == 2 && d > 28 || d <= 0) {
		return false;
	}
	else if (d>31 || d<=0 || m>12 || m<=0) {
		return false;
	}

	return true;
}


int DigitPos(long num, int k) {
	int copy = num, del = 1, counter = 1;
	while (copy > 9) {
		del *= 10;
		copy /= 10;
		counter++;
	}
	if (counter < k) {
		return -1;
	}
	for (int i = 1; i < k; i++) {
		del /= 10;
	}

	return num/del%10;
}



int calcMatrix(int** matrix, int n) {
	int sum = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int p = 1; p < n; p++) {
			sum += matrix[i][p];
		}
	}
	return sum;
}


int Analyze(int arr[], int i) {
	int fst = 0, sec = 0;
	for (int p = 0; p < i; p++) {
		for (int a = 0; a < p; a++) {
			fst += arr[a];
		}
		for (int b = p; b < i; b++) {
			sec += arr[b];
		}
		if (fst == sec) {
			return 1;
		}
		else {
			fst = 0;
			sec = 0;
		}
	}
	return 0;
}


#include<string>
struct Cars {
	int reg_n, chasis_n, engine_n;
	string brands;
	string colors;
	string name;
};




int minIndex(int arr[], int s, int e)
{
	int sml = INT_MAX;
	int mindex = -1;;
	for (int i = s; i < e; i++) {
		if (sml > arr[i]) {
			sml = arr[i];
			mindex = i;
		}
	}
	return mindex;
}

void fun(int arr[], int start_index, int end_index)
{
	if (start_index >= end_index)
		return;
	int min_index;
	int min = INT_MAX;
	//min_index = minIndex(arr, start_index, end_index);
	for (int i = start_index; i < end_index; i++) {
		if (min > arr[i]) {
			min = arr[i];
			min_index = i;
		}
	}

	swap(arr[start_index], arr[min_index]);

	fun(arr, start_index + 1, end_index);
}

*/
/*
int main() {

	
	int arr[8] = { 2,6,5,8,4,7,9,3 };
	fun(arr, 0, 8);
	for (int i = 0; i < 8; i++) {
		cout << arr[i] << " ";
	}

	
	Cars car[5];
	for (int i = 0; i < 5; i++) {
		cin >> car[i].reg_n;
		cin >> car[i].chasis_n;
		cin >> car[i].colors;
	}
	int counter = 0;
	for (int i = 0; i < 5; i++) {
		if (car[i].colors == "red") {
			counter++;
		}
	}
	cout << counter;
	
	int m[] = { 1,3,0,0,4};
	cout << Analyze(m, 5);


	
	int** matrix = new int* [5];
	for (int i = 0; i < 5; i++) {
		matrix[i] = new int[5]{ 1 + i,2 + i,3 + i,4 + i,5 + i };
	}
	cout << calcMatrix(matrix, 5);
	for (int i = 0; i < 5; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
	*/
	//char date[] = "01.03";
	//char str[] = "adsaACDsdWEEsZ";
	//cout << DigitPos(12, 2);
	//cout << CheckDate(date);
	//Revert(str);
	/*
	double a = 0.6541867611;
	double del = 1, d = 1;
	int k = 7;
	for (int i = 1; i <= k; i++) {
		del /= 10;
		d *= 10;
	}
	int b = a / del;
	double c = b / d;
	cout << c;
	

	return 0;
}

*/