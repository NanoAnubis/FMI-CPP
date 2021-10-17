#include<iostream>
#include<vector>
using namespace std;


void swap(vector<long long>& arr, long long a, long long b) {

	long long tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;

	return;
}

long long partition(vector<long long>& arr, long long low, long long high) {
	long long pivot = arr[high];
	long long i = low;
	for (long long j = low; j < high; j++) {
			if (arr[j] <= pivot) {
				swap(arr, i, j);
				i++;
			}
	}
	swap(arr, i, high);
	return i;
}

void sort(vector<long long>& arr, long long low, long long high)
    {
        if (low < high)
        {
			long long pi = partition(arr, low, high);
  
            sort(arr, low, pi-1);
            sort(arr, pi+1, high);
        }
    }





int main() {

	long long n;
	cin >> n;
	vector<long long> input;
	for (long long i = 0; i < n; i++) {
		long long tmp;
		cin >> tmp;
		input.push_back(tmp);
	}
	long long k;
	cin >> k;
	

	sort(input, 0, n-1);

	long long output = input[0];

	for (long long i = 1; i < k; i++) {
		output += input[i];
	}
	cout << output << endl;

	return 0;
}