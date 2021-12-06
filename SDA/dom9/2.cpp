//#include<bits/stdc++.h>
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k;
    cin >> n >> k;

    long long result = 0;

    unordered_map<long long, long long> left;
    unordered_map<long long, long long> right;
    vector<long long> storage;


    for (long long i = 0; i < n; i++) {
        long long tmp;
        cin >> tmp;
        storage.push_back(tmp);
        right[tmp]++;
        //left[tmp] = 0;
    }

    left[storage[0]]++;
    right[storage[0]]--;

    for (long long i = 1; i < n; i++) {
        right[storage[i]]--;
        long long l = 0, r = 0;
        long long y = storage[i];
        if (y % k == 0 && left.count(y / k) > 0)l = left[y / k];
        if (right.count(y * k) > 0)r = right[y * k];
        if (r > 0 && l > 0) {
            result += (l * r);
        }
        left[storage[i]]++;
    }

    std::cout << result;

    return 0;
}