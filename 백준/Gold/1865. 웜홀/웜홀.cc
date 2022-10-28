#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1'000'000'000;

struct edge {
    int from, to, value;

    edge(int from, int to, int value) : from(from), to(to), value(value) {};
};

vector<edge> edges;

int *nodes;

int node_n;

bool updated;

void input() {
    updated = false;
    int edge_n, hole_n;
    cin >> node_n >> edge_n >> hole_n;

    delete[] nodes;
    nodes = new int[node_n + 1];
    fill_n(nodes, node_n + 1, INF);

    edges.clear();
    int from, to, value;
    while (edge_n--) {
        cin >> from >> to >> value;
        edges.emplace_back(from, to, value);
        edges.emplace_back(to, from, value);
    }
    while (hole_n--) {
        cin >> from >> to >> value;
        edges.emplace_back(from, to, -value);
    }
}

void solve() {
    nodes[1] = 0;

    for (int i = 1; i < node_n; ++i) {
        for (const auto &edge: edges) {
            if (nodes[edge.to] > nodes[edge.from] + edge.value)
                nodes[edge.to] = nodes[edge.from] + edge.value;
        }
    }

    for (const auto &edge: edges) {
        if (nodes[edge.to] > nodes[edge.from] + edge.value) {
            updated = true;
            break;
        }
    }
}

void output() {
    if (updated) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test;
    cin >> test;

    while (test--) {
        input();
        solve();
        output();
    }
}