#include<iostream>
using namespace std;

bool IsSequence(int* arr, int size, int number) {
	int counter = 0, equal = 0;
	bool flag = 1;
	int* Tmp_arr = nullptr;
	Tmp_arr = new int[size];
	for (int i = 0; i < size; i++) {
		Tmp_arr[i] = arr[i];
	}
	for (int i = 0; i < size - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			counter++;
			arr[i + 1] = arr[i];
		}
		if (counter > number) {
			flag = 0;
		}
	}
	if (flag == 1) {
		delete[]Tmp_arr;
		return 1;
	}
	counter = 0;
	for (int i = size - 1; i > 0 ; i--) {
		if (Tmp_arr[i] < Tmp_arr[i - 1]) {
			counter++;
			Tmp_arr[i - 1] = Tmp_arr[i];
		}
		if (counter > number) {
			delete[]Tmp_arr;
			return 0;
		}
	}
	delete[]Tmp_arr;
	return 1;
}

int main() {
	int* Array = nullptr;
	int M = 0, N = 0;
	cin >> N >> M;
	Array = new int[M];
	for (int i = 0; i < M; i++) {
		cin >> Array[i];
	}
	cout<<IsSequence(Array, M, N);
	delete[]Array;
	return 0;
}
