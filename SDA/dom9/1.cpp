#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


int main() {

    long long n;
    cin >> n;

    unordered_map<long long, int> keys;
    vector<long long> storage;
    long long broken_doors = 0;

    for (int i = 0; i < n; i++) {
        long long k;
        cin >> k;
        storage.push_back(k);
    }

    for (int i = 0; i < n; i++) {
        long long d;
        cin >> d;
        keys[storage[i]] ++;
        if (keys[d] >= 1) {
            keys[d] --;
        }
        else {
            broken_doors++;
        }
    }

    cout << broken_doors;

    return 0;
}