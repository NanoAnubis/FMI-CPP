//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

const int MOD = 1000000000 + 7;
const int BASE = 257;

vector<long long> powers(1,1);

void powerify(int num) {
    for (int i = powers.size(); i <= num; i++) {
        powers.push_back((powers[i - 1] * BASE) % MOD);
    }
}

vector<long long> prefix_hash(const string& str) {
    vector<long long> hashes;

    hashes.push_back(0);
    for (int i = 0; i < (int)str.size(); i++) {
        hashes.push_back((hashes[i] + str[i] * powers[i]) % MOD);
    }
    return hashes;
}



int main() {

    string first, second;

    cin >> first;
    cin >> second;

    string seq;
    string text;
    if (first.size() > second.size()) {
        seq = second;
        text = first;
    }
    else {
        seq = first;
        text = second;
    }

    powerify(text.size());
    vector<long long> text_hashes = prefix_hash(text);
    vector<long long> seq_hashes = prefix_hash(seq);
    long long seq_hash, text_hash;
    
    for (int i = 0; i < (int)seq.size(); i++) {
        for (int s = 0; s <= i; s++) {

            seq_hash = (seq_hashes[seq.size() + s - i] + MOD - seq_hashes[s]) % MOD;
            
            for (int p = (int)seq.size() - i ; p <= (int)text.size(); p++) {
                text_hash = (text_hashes[p] + MOD - text_hashes[p - (int)seq.size() + i]) % MOD;
                if (text_hash == seq_hash) {
                    cout << (int)seq.size() - i;
                    return 0;
                }
            }
        }
    }

    cout << 0;

    return 0;
}