//#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<algorithm>

using namespace std;

map<char, set<char>> alphabet;
map<char, bool> visited;
vector<char> output;

void topo(char s) {
    visited[s] = 1;
    auto it = alphabet[s].begin();
    while (it != alphabet[s].end()) {
        if (visited[*it] == 0) {
            topo(*it);
        }
        it++;
    }
    output.push_back(s);
}

void start_topo() {

    auto it = visited.begin();
    while (it != visited.end()) {
        if (visited[it->first] == 0) {
            topo(it->first);
        }
        it++;
    }
    reverse(output.begin(), output.end());
}

int main() {
    int n;
    cin >> n;

    string prev;
    cin >> prev;
    //char start = prev[0];

    for (int i = 0; i < (int)prev.size(); i++) {
        alphabet[prev[i]];
        visited[prev[i]];
    }

    for (int i = 1; i < n; i++) {
        string curr;
        cin >> curr;

        for (int i = 0; i < (int)curr.size(); i++) {
            alphabet[curr[i]];
            visited[curr[i]];
        }

        for (int p = 0; p < (int)min(curr.size(), prev.size()); p++) {
            if (prev[p] != curr[p]) {
                alphabet[prev[p]].insert(curr[p]);
                break;
            }

        }

        prev = curr;
    }

    start_topo();



    for (char i : output) {
        cout << i << " ";
    }

    return 0;
}
