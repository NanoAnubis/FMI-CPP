//#include<bits/stdc++.h>
#include<iostream>
#include<unordered_map>

using namespace std;


int main() {

    int n;
    cin >> n;

    unordered_map<int, int> numbers;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        numbers[tmp]++;
    }

    auto it = numbers.begin();
    int sum = 0;
    while (it != numbers.end()) {
        if (it->second % 2 != 0) {
            sum += it->first*it->second;
        }
        it++;
    }

    cout << sum;

    return 0;
}
