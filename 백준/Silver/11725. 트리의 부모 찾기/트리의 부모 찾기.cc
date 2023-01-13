//
// Created by 99woo on 2023-01-13.
//

#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;
using vii = vector<pii>;
using ll = long long;

#define endl '\n'
#define em emplace
#define emb emplace_back
#define all(x) x.begin(), x.end()
#define fastio iostream::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

vector<vector<int>> graph;
vector<int> pars;
vector<bool> visited;
int n;

void input() {
    cin >> n;

    graph.resize(n + 1);
    visited.resize(n + 1);
    pars.resize(n + 1);

    int n1, n2;

    for (int i = 1; i < n; ++i) {
        cin >> n1 >> n2;

        graph[n1].emb(n2);
        graph[n2].emb(n1);
    }
}

void solve() {
    queue<int> q;
    q.em(1);
    visited[1] = true;

    int now;
    while (!q.empty()) {
        now = q.front();
        q.pop();

        for (const auto &i: graph[now]) {
            if (visited[i]) continue;

            visited[i] = true;
            pars[i] = now;

            q.em(i);
        }
    }
}

void output() {
    for (int i = 2; i <= n; ++i) cout << pars[i] << endl;
}

int main() {
    fastio

    input();
    solve();
    output();
}