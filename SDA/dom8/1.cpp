#include <bits/stdc++.h>
#include<iostream>
#include<set>
#include<vector>
#include<iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(1);

    int n;
    cin >> n;

    multiset<double> numbers;
    vector<double> output;
    auto mid = numbers.begin();

    for (int i = 1; i <= n; i++) {
        double tmp;
        cin >> tmp;
        numbers.insert(tmp);
        if (i == 1) mid = numbers.begin();
        if (tmp < *mid && i != 1) mid--;

        if (numbers.size() % 2 != 0) output.push_back(*mid);
        else {
            double tmp = *mid;
            mid++;
            tmp += *mid;
            tmp /= 2;
            output.push_back(tmp);
        }
    }
    for (int i = 0; i < (int)output.size(); i++) {

        cout << output[i] << '\n';

    }

    return 0;
}