#include<iostream>
#include<vector>
#include<utility>
#include<unordered_set>

using namespace std;

int n, m;

vector<pair<int, int>> edges;
vector<int> parent_edge;
vector<unordered_set<int>> children;

vector<bool>visited;

int rebuild_roots(int edge) {
    if (visited[edge]) {
        return parent_edge[edge];
    }
    visited[edge] = 1;

    if (edge == parent_edge[edge]) {
        return edge;
    }
    return parent_edge[edge] = rebuild_roots(parent_edge[edge]);
}

int find_root(int node) {
    if (parent_edge[node] == node) {
        return node;
    }
    return parent_edge[node] = find_root(parent_edge[node]);
}

void unite_roots(int r1, int r2) {
    parent_edge[r1] = r2;
    children[r1].merge(children[r2]);
    children[r2] = children[r1];
}

void kruskal() {
    for (int i = 0; i <= n; i++) {
        parent_edge[i] = i;
    }

    for (pair<int, int> edge : edges) {
        int root1 = find_root(edge.first);
        int root2 = find_root(edge.second);

        if (root1 != root2) {
            unite_roots(root1, root2);
        }
    }
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n >> m;

    parent_edge.resize(n + 1);
    children.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        children[i].insert(i);
    }

    for (int i = 0; i < m; i++) {
        int f, s;
        cin >> f >> s;
        edges.push_back({ f,s });
        children[f].insert(s);
        children[s].insert(f);
    }

    kruskal();

    visited.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) rebuild_roots(i);
    }

    vector<bool> output;

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int type, f, s;
        cin >> type >> f >> s;
        switch (type) {
        case 1: {
            output.push_back(max(children[parent_edge[f]].count(s), children[parent_edge[s]].count(f)));
            break;
        }
        case 2: {
            int root1 = find_root(f);
            int root2 = find_root(s);

            if (root1 != root2) {
                unite_roots(root1, root2);
            }
            visited.clear();
            visited.resize(n + 1);
            for (int p = 1; p <= n; p++) {
                if (!visited[p]) rebuild_roots(p);
            }
            break;
        }
        }

    }

    for (bool o : output) {
        cout << o;
    }

    return 0;
}