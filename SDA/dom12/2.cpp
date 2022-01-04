#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

long long n, m;

struct City {
    long long from;
    long long to;
    long long workload;
    long long profit;
    long long index;

    City(long long f =0, long long t=0, long long w=0, long long p=0, long long i=0):from(f),to(t),workload(w),profit(p),index(i) {}

    const bool operator<(const City& r) const {
        if (workload < r.workload ) return true;
        else if (workload  == r.workload && profit > r.profit) return true;
        else return false;
    }

};


vector<City> cities;
vector<long long> parent_edge;
vector<long long> output;

int find_root(long long node) {
    if (parent_edge[node] == node) {
        return node;
    }
    return parent_edge[node] = find_root(parent_edge[node]);
}

void unite_roots(long long r1, long long r2) {
    parent_edge[r1] = r2;
}

void kruskal() {
    sort(cities.begin(), cities.end());

    for (long long i = 0; i <= n; i++) {
        parent_edge[i] = i;
    }

    for (City& edge : cities) {
        long long root1 = find_root(edge.from);
        long long root2 = find_root(edge.to);

        if (root1 != root2) {
            unite_roots(root1, root2);
            output.push_back(edge.index);
        }
    }
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n >> m;

    parent_edge.resize(n + 1);

    for (long long i = 0; i < m; i++) {
        long long f, s, w, p;
        cin >> f >> s >> w >> p;
        cities.push_back(City(f,s,w,p,i+1));
    }

    kruskal();


    for (long long o : output) {
        cout << o<<'\n';
    }

    return 0;
}