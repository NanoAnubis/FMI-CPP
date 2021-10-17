#include<iostream>
#include<vector>
#include<utility>
using namespace std;



void merge(vector<pair<pair<double, int>, long long>>& arr, int low, int mid, int high) {
    vector<pair<pair<double, int>, long long>> left;
    vector<pair<pair<double, int>, long long>> right;

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
        if (left[i].first < right[j].first) {
            arr[index++] = left[i++];
        }
        else if (left[i].first == right[j].first) {
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

void merge_sort(vector<pair<pair<double, int>, long long>>& arr, int low, int high) {

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
    vector<pair<pair<double,int>, long long>>boys;

    for (long i = 0; i < n; i++)
    {
        long long d, t;
        cin >> d;
        cin >> t;
        double Ef;
        Ef = ((d * d) / 4.0) / t;

        pair<double, int> tmp1{ Ef,d };
        pair<pair<double, int>, long long> tmp2{ tmp1,i + 1 };
        boys.push_back(tmp2);
    }

    merge_sort(boys, 0, boys.size() - 1);


    for (long i = n - 1; i >= 0; i--) {
        cout << boys[i].second << " ";
    }

    return 0;
}