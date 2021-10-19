#include<iostream>
#include<vector>
using namespace std;


void merge(vector<pair<pair<double, int>, long>>& arr, int low, int mid, int high) {
    vector<pair<pair<double, int>, long>> left;
    vector<pair<pair<double, int>, long>> right;

    for (int i = low; i <= mid; i++) {
        left.push_back(arr[i]);
    }
    for (int i = mid + 1; i <= high; i++) {
        right.push_back(arr[i]);
    }

    int i = 0;
    int j = 0;
    int index = low;

    while (i < left.size() && j < right.size()) {
        if (left[i].first.first < right[j].first.first) {
            arr[index++] = left[i++];
        }
        else if (left[i].first.first == right[j].first.first) {
            if (left[i].first.second < right[j].first.second) {
                arr[index++] = left[i++];
            }
            else {
                arr[index++] = right[j++];
            }
        }
        else {
            arr[index++] = right[j++];
        }
    }

    while (i < left.size()) {
        arr[index++] = left[i++];
    }

    while (j < right.size()) {
        arr[index++] = right[j++];
    }
}

void merge_sort(vector<pair<pair<double, int>, long>>& arr, int low, int high) {

    if (low < high) {
        int mid = (low + high) / 2;

        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

int main() {

	long n;
	cin >> n;
	vector<pair<pair<double, int>,long>> teams;

	for (long i = 0; i < n; i++) {
		int x;
		cin >> x;
		double y;
		cin >> y;
		double score = (x*x)/y;
		pair<double, long>tmp{ score,x};
		pair<pair<double, long>, long>tmp1{ tmp,i + 1 };
		teams.push_back(tmp1);
	}
	
    merge_sort(teams, 0, teams.size() - 1);

    for (long i = teams.size() - 1; i >= 0; i--) {
        cout << teams[i].second << " ";
    }

	return 0;
}