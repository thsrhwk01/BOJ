#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> graph;

vector<int> result1, result2;

int ans;

void input() {
    int n;
    cin >> n;

    graph.resize(n + 1);

    result1.resize(n + 1);
    result2.resize(n + 1);
    fill(result1.begin(), result1.end(), -1);
    fill(result2.begin(), result2.end(), -1);

    int from, to, value;

    for (int i = 0; i < n - 1; ++i) {
        cin >> from >> to >> value;
        graph[from].emplace_back(to, value);
        graph[to].emplace_back(from, value);
    }
}

void dfs(int start, vector<int> &result) {
    stack<pair<int, int>> stk;

    stk.emplace(start, 0);
    while (!stk.empty()) {
        auto now = stk.top();
        stk.pop();

        if (result[now.first] != -1) continue;

        result[now.first] = now.second;

        for (const auto &node: graph[now.first])
            stk.emplace(node.first, node.second + now.second);
    }
}

void solve() {
    dfs(1, result1);
    dfs(max_element(result1.begin(), result1.end()) - result1.begin(), result2);
}

void output() {
    cout << *max_element(result2.begin(), result2.end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    solve();
    output();
}