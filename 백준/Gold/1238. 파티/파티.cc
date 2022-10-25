#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> come, go;

vector<int> come_time, go_time;

int ans = 0, start;

struct cmp {
    bool operator()(const pair<int, int> &rhs, const pair<int, int> &lhs) noexcept {
        return rhs.second > lhs.second;
    }
};

void input() {
    int node_n, edge_n;
    cin >> node_n >> edge_n >> start;

    come.resize(node_n + 1);
    go.resize(node_n + 1);

    come_time.resize(node_n + 1);
    fill(come_time.begin(), come_time.end(), -1);
    go_time.resize(node_n + 1);
    fill(go_time.begin(), go_time.end(), -1);

    int from, to, weight;
    while (edge_n--) {
        cin >> from >> to >> weight;
        come[to].emplace_back(from, weight);
        go[from].emplace_back(to, weight);
    }
}

void solve() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> come_q;
    come_q.emplace(start, 0);

    while (!come_q.empty()) {
        int node = come_q.top().first;
        int time = come_q.top().second;

        come_q.pop();

        if (come_time[node] != -1) continue;

        come_time[node] = time;

        for (const auto &to: come[node]) {
            if (come_time[to.first] == -1) {
                come_q.emplace(to.first, time + to.second);
            }
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> go_q;
    go_q.emplace(start, 0);

    while (!go_q.empty()) {
        int node = go_q.top().first;
        int time = go_q.top().second;

        go_q.pop();

        if (go_time[node] != -1) continue;

        go_time[node] = time;

        for (const auto &to: go[node]) {
            if (go_time[to.first] == -1) {
                go_q.emplace(to.first, time + to.second);
            }
        }
    }

    auto it1 = come_time.begin() + 1;
    auto it2 = go_time.begin() + 1;

    while (it1 != come_time.end())
        ans = max(ans, *it1++ + *it2++);
}

void output() {
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    solve();
    output();
}