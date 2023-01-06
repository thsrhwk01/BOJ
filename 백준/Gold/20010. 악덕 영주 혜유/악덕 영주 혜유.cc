//
// Created by 99woo on 2023-01-06.
//
#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using pii = pair<int, int>;
using vii = vector<pii>;
using ll = long long;

#define endl '\n'
#define em emplace
#define emb emplace_back
#define all(x) x.begin(), x.end()
#define fastio iostream::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

const int INF = 0x3f3f3f3f;           // infinite

vi uf;                                // for union-find
vector<tuple<int, int, int>> edges;   // {value, from, to}
vector<vector<pii>> graph;            // graph[from][to] = value
int node_n, edge_n;

int ans1 = 0, ans2;

void input() {
    cin >> node_n >> edge_n;

    graph.resize(node_n);

    uf.resize(node_n);
    iota(all(uf), 0); // filling 0, 1, 2, 3, 4, 5 ... in uf

    int from, to, value;
    while (edge_n--) {
        cin >> from >> to >> value;

        edges.emb(value, from, to);
    }
}

int getParent(int node) {
    if (uf[node] == node) return node;
    else return getParent(uf[node]);
}

void unionParent(int l, int r) {
    l = getParent(l);
    r = getParent(r);

    uf[max(l, r)] = min(l, r);
}

bool isSameParent(int l, int r) {
    return getParent(l) == getParent(r);
}

void dfs(vi &result, int now, int sum) {
    if (result[now] < sum) return;

    result[now] = sum;

    for (const auto& edge: graph[now]) {
        dfs(result, edge.first, sum + edge.second);
    }
}

void solve() {
    sort(all(edges));

    int value, from, to;
    for (const auto &edge: edges) {
        tie(value, from, to) = edge;

        if (isSameParent(from, to)) continue;

        graph[from].emb(to, value);
        graph[to].emb(from, value);

        unionParent(from, to);

        ans1 += value;
    }

    vi res1(node_n), res2(node_n);
    fill(all(res1), INF);
    fill(all(res2), INF);

    dfs(res1, 0, 0);
    dfs(res2, max_element(all(res1))- res1.begin(), 0);

    ans2 = *max_element(all(res2));
}

void output() {
    cout << ans1 << endl << ans2;
}

int main() {
    fastio

    input();
    solve();
    output();
}