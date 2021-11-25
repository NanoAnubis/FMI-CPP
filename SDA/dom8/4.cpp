#include<iostream>
#include<vector>
//#include<tuple>
#include<utility>
#include<algorithm>
using namespace std;


bool compare(pair<long long, int>& lhs, pair<long long, int> rhs) {
    if (lhs.first > rhs.first)return true;
    else if (lhs.first < rhs.first) return false;
    else return (lhs.second < rhs.second);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n, k;
    cin >> n >> k;

    vector<long long> operators(k,0);
    vector<pair<long long, int>> counters(k, {0,0});
    for (int i = 0; i < k; i++) {
        counters[i].second = i;
    }


    for (int i = 0; i < n; i++) {
        long long t, l;
        cin >> t >> l;
        long long go_to = i % k;
        for (int p = 0; p < k; p++) {
            if (go_to + p == k)go_to -= k;
            if (operators[go_to + p] <= t) {
                operators[go_to + p] = t + l;
                counters[go_to + p].first++;
                break;
            }
        }
    }

    sort(counters.begin(), counters.end(), compare);

    int i = 0;
    while (counters[0].first == counters[i].first) {
        cout << counters[i].second << " ";
        i++;
    }

    return 0;
}