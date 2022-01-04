#include<iostream>
#include<vector>
#include<set>
#include<utility>
#include<climits>
using namespace std;

const int mod = 1000000007;

long n, m;
vector<vector<pair<long, long>>> weighted_graph(100001);
vector<long> dist(100001, LONG_MAX);
vector<long> paths(100001);

void calculate_distances(long start) {
    dist[start] = 0;
    paths[start] = 1;

    set<pair<long, long>> storage;
    storage.insert({ 0,start });

    while (!storage.empty()) {
        long edge = storage.begin()->second;
        storage.erase(storage.begin());

        auto link = weighted_graph[edge].begin();
        while (link != weighted_graph[edge].end()) {
            if (dist[link->first] > dist[edge] + link->second) {
                storage.erase({ dist[link->first], link->first });
                dist[link->first] = dist[edge] + link->second;
                storage.insert({ dist[link->first],link->first });
                paths[link->first] = paths[edge];
            }
            else if (dist[link->first] == dist[edge] + link->second) {
                paths[link->first] = (paths[link->first] + paths[edge]) % mod;

            }
            link++;
        }

    }
}

int main() {

    cin >> n >> m;

    long start = 1;

    for (long i = 1; i <= m; i++) {
        long from, to, weight;
        cin >> from >> to >> weight;
        weighted_graph[from].push_back({ to,weight });
    }

    calculate_distances(start);

    if (dist[n] == LONG_MAX) {
        cout << -1 << " " << 0;
    }
    else {
        cout << dist[n] << " " << paths[n] % mod;
    }
    return 0;
}