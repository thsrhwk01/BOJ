#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

string dfs_string;
string bfs_string;

void dfs(map<int, bool>& visited, const vector<set<int>>& nodes, int now) {
    if (visited[now]) return;
    visited[now] = true;
    dfs_string += (to_string(now) + ' ');

    for (const auto& x : nodes[now]) dfs(visited, nodes, x);
}

void bfs(map<int, bool>& visited, const vector<set<int>>& nodes, int start) {
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (visited[now]) continue;

        bfs_string += (to_string(now) + ' ');
        visited[now] = true;
        for (const auto& x : nodes[now]) q.push(x);
    }
}

int main() {
    int node_n, edge_n, start; cin >> node_n >> edge_n >> start;
    vector<set<int>> nodes(node_n + 1);

    while (edge_n--) {
        int from, to; cin >> from >> to;
        nodes[from].insert(to);
        nodes[to].insert(from);
    }

    map<int, bool> visited;
    for (int i = 1; i <= node_n; ++i) visited[i] = false;

    dfs(visited, nodes, start);
    cout << dfs_string << '\n';

    for (int i = 1; i <= node_n; ++i) visited[i] = false;
    bfs(visited, nodes, start);
    cout << bfs_string;
}