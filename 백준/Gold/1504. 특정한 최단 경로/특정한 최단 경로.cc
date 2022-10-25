#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> graph;

bool able = false;

int node_n, vn1, vn2;

bool *visited;

int ans;

struct cmp {
    bool operator()(const pair<int, int> &rhs, const pair<int, int> &lhs) {
        return rhs.second > lhs.second;
    }
};

void input() {
    int edge_n;
    cin >> node_n >> edge_n;

    graph.resize(node_n + 1);
    visited = new bool[node_n + 1];

    int from, to, value;
    while (edge_n--) {
        cin >> from >> to >> value;
        graph[from].emplace_back(to, value);
        graph[to].emplace_back(from, value);
    }

    cin >> vn1 >> vn2;
}


int dijkstra(int start, int end) {
    fill(visited, visited + node_n + 1, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
    q.emplace(start, 0);

    while (!q.empty()) {
        auto now = q.top();

        q.pop();

        if (visited[now.first]) continue;

        if (now.first== end) {
            able = true;
            return now.second;
        }

        visited[now.first] = true;

        for (const auto &node: graph[now.first])
            if (!visited[node.first]) q.emplace(node.first, now.second + node.second);
    }

    able = false;
    return 0;
}


void solve() {
    int first_case = 0, second_case = 0;

    first_case += dijkstra(1, vn1);
    if (!able) return;
    first_case += dijkstra(vn1, vn2);
    if (!able) return;
    first_case += dijkstra(vn2, node_n);
    if (!able) return;

    second_case += dijkstra(1, vn2) + dijkstra(vn2, vn1) + dijkstra(vn1, node_n);

    ans = min(first_case, second_case);
}


void output() {
    if (!able) cout << -1;
    else cout << ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    solve();
    output();
}