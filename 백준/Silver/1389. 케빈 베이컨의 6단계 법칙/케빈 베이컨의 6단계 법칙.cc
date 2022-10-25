#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void bfs(const vector<vector<int>>& nodes, vector<int>& tmp, int start) {
    queue<pair<int, int>> q;
    q.push({start, 0});

    while (!q.empty()) {
        auto now = q.front();
        q.pop();

        if (tmp[now.first] != -1) continue;
        tmp[now.first] = now.second;

        for (const auto& another_node: nodes[now.first]) q.push({another_node, now.second + 1});
    }
}

int main() {
    int node_n, edge_n; cin >> node_n >> edge_n;
    vector<vector<int>> nodes(node_n + 1);

    while (edge_n--) {
        int from, to; cin >> from >> to;
        nodes[from].emplace_back(to);
        nodes[to].emplace_back(from);
    }

    pair<int, int> ans = {0, 5001};

    for (int i = 1; i <= node_n; ++i) {
        vector<int> tmp(node_n + 1);
        fill(tmp.begin(), tmp.end(), -1);
        tmp[0] = 0;

        bfs(nodes, tmp, i);
        int hehe = accumulate(tmp.begin(), tmp.end(), 0);

        if (ans.second > hehe) ans = {i, hehe};
    }

    cout << ans.first;
}