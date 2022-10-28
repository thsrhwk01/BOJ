#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, ans;

int a, b;

struct cmp {
    bool operator()(const pair<int, int> &rhs, const pair<int, int> &lhs) {
        return rhs.second > lhs.second;
    }
};

vector<vector<pair<int, int>>> busses;
vector<int> dist;

void input() {
    int m;
    cin >> n >> m;

    busses.resize(n + 1);
    dist.resize(n + 1);

    fill(dist.begin(), dist.end(), -1);

    int from, to, value;

    while (m--) {
        cin >> from >> to >> value;
        busses[from].emplace_back(to, value);
    }

    cin >> a >> b;
}

//solved by Dijkstra
void solve() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.emplace(a, 0);

    while (!pq.empty()) {
        auto now = pq.top();
        pq.pop();

        if (dist[now.first] != -1) continue;

        dist[now.first] = now.second;
        if (now.first == b) return;

        for (const auto &bus: busses[now.first]) {
            if (dist[bus.first] == -1) pq.emplace(bus.first, now.second + bus.second);
        }
    }
}

void output() {
    cout << dist[b];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    solve();
    output();
}