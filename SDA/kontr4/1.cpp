#include<iostream>
#include<set>
#include<utility>
using namespace std;


int main() {

    long long n;
    cin >> n;

    multiset<pair<long long, long long>> tasks;

    long long time = 0;
    long long min0 = 100001;
    long long max0 = -1;

    for (int i = 0; i < n; i++) {
        long long tmp;
        cin >> tmp;
        tasks.insert({ tmp,i });
    }

    auto it = tasks.begin();

    while (!tasks.empty()) {
        if (it->second <= time) {
            long long tmp = time - it->second + it->first;
            max0 = max(tmp, max0);
            min0 = min(tmp, min0);

            time += it->first;

            tasks.erase(it);
            it = tasks.begin();

        }
        else it++;
    }

    cout << min0 << " " << max0;

    return 0;
}