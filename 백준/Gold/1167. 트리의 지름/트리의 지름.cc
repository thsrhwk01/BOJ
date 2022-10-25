#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> graph;

long long * result;

int v;

void input() {
    cin >> v;
    graph.resize(v + 1);
    result = new long long [v + 1];
    fill_n(result, v + 1, -1);

    int node, edge, value;
    for (int i = 1; i <= v; ++i) {
        cin >> node;

        while (cin >> edge && edge != -1) {
            cin >> value;
            graph[node].emplace_back(edge, value);
        }
    }
}

void dfs(int node = 1, long long value = 0) {
    result[node] = value;

    for (const auto &n: graph[node]) {
        if (result[n.first] == -1) {
            dfs(n.first, value + n.second);
        }
    }
}

void solve() {
    dfs();

    auto deepest_node = max_element(result, result + v + 1);

    fill_n(result, v + 1, -1);

    dfs(deepest_node - result);

    cout << *max_element(result, result + v + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();

    solve();
}