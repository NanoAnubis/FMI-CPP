//#include<bits/stdc++.h>
#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;


int main() {

    int n;
    cin >> n;

    unordered_map<string,int> cypher;
    vector<string> storage;

    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        cypher[tmp]++;
        storage.push_back(tmp);
    }
    
    for (int i = 0; i < n; i++) {
        cout << cypher[storage[i]] << ' ';

    }


    return 0;
}
