#include<iostream>
using namespace std;

bool IsSequence(int* arr, int size, int number) {
	int counter = 0;
	for (int i = 0; i < size - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			counter++;
		}
		if (counter > number) {
			return 0;
		}
	}
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
