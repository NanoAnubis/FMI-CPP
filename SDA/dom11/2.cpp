#include<iostream>
#include<vector>
#include<set>
#include<utility>
#include<climits>
using namespace std;

long n, m, k;
vector<vector<pair<long,pair<long, long>>>> weighted_graph(100001);
vector<long> weight_needed(100001, LONG_MAX);
vector<long> time_needed(100001, 0);

void calculate_minweight(long start) {
    weight_needed[start] = 0;

    set<pair<pair<long,long>, long>> storage;
    storage.insert({ {0,0}, start});

    while (!storage.empty()) {
        long curr = storage.begin()->second;
        storage.erase(storage.begin());

        auto next = weighted_graph[curr].begin();
        while (next != weighted_graph[curr].end()) {
            if (weight_needed[next->first] > max(weight_needed[curr],next->second.first) && time_needed[curr]+next->second.second<=k) {
                storage.erase({ {weight_needed[next->first],time_needed[next->first]}, next->first});
                weight_needed[next->first] = max(weight_needed[curr], next->second.first);
                time_needed[next->first] = time_needed[curr] + next->second.second;
                storage.insert({{ weight_needed[next->first],time_needed[next->first] }, next->first });
            }
            else {
                next++;
                if (next == weighted_graph[curr].end()) {
                    if(curr!=start)weight_needed[curr] = LONG_MAX;
                }
                continue;
            }

            next++;
        }

    }
}

int main() {

    cin >> n >> m >> k;

    long start = 1;

    for (long i = 1; i <= m; i++) {
        long from, to, weight, time;
        cin >> from >> to >> weight >> time;
        weighted_graph[from].push_back({ to,{weight,time} });
    }

    calculate_minweight(start);

    if (weight_needed[n] == LONG_MAX) {
        cout << -1;
    }
    else {
        cout << weight_needed[n];
    }
    return 0;
}