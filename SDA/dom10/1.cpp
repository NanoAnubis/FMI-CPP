//#include<bits/stdc++.h>
#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>

using namespace std;


bool search(int num,vector<bool> storage, unordered_map<int, list<int>>& distribution) {
    if (storage[num] == 1) {
        return 1;
    }
    else {
        storage[num] = 1;
    }

    if (distribution.count(num)>0) {
        auto link = distribution[num].begin();
        while (link != distribution[num].end()) {
            if (search(*link, storage, distribution))return 1;
            else link++;
        }
    }
    return 0;
}



int main() {

    int q, e;
    cin >> q;

    vector<bool> output;

    for (int i = 1; i <= q; i++) {
        cin >> e;

        unordered_map<int, list<int>> distribution;
        vector<bool> storage;

        for (int p = 1; p <= e; p++) {
            int start, end;
            cin >> start >> end;

            distribution[start].push_back(end);
            if (start >= (int)storage.size()) {
                storage.resize(start + 1);
            }
            if (end >= (int)storage.size()) {
                storage.resize(end + 1);
            }
        }

        bool breaker = false;

        auto it = distribution.begin();
        
        int storage_size = storage.size();
        
        while (it != distribution.end()) {
            storage[it->first] = 1;
            auto link = it->second.begin();
            while (link != it->second.end()) {
                breaker = search(*link, storage, distribution);
                if (breaker)break;
                link++;
            }

            if (breaker)break;

            storage.clear();
            storage.resize(storage_size);
            it++;
        }

        output.push_back(breaker);

    }

    for (bool i : output) {
        cout << i << " ";
    }

    return 0;
}
