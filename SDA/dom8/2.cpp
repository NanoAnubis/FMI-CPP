#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<utility>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n;
    cin >> n;
    
    multimap<pair<long long, long long>,int> tasks;
    long long time = 0;

    for (int i = 0; i < n; i++) {
        long long t, f;
        cin >> t >> f;
        pair<long long, long long> tmp{ f,t };
        tasks.insert({ tmp, i });
    }


    auto curr = tasks.begin();
    multiset<long long>min_starts;
    string output;

    while (!tasks.empty()) {
        if ((*curr).first.second <= time) {
            auto next = curr;
            next++;
            while (next != tasks.end() && (*next).first.first == (*curr).first.first 
                && (*next).first.second <= time) {
                if ((*next).second < (*curr).second) {
                    curr = next;
                }
                next++;
            }

            output += to_string((*curr).second)+' ';
            time += (*curr).first.first;
            tasks.erase(curr);
            curr = tasks.begin();
            min_starts.clear();
        }
        else {
            min_starts.insert((*curr).first.second);
            curr++;
        }
        if (curr == tasks.end() && min_starts.size()!=0) {
            curr = tasks.begin();
            time = *min_starts.begin();
            min_starts.clear();
        }
    }

    cout << output;

    return 0;
}



/*

5
3 6
0 4
4 5
10 3
2 5


1 2 4 3 0
*/