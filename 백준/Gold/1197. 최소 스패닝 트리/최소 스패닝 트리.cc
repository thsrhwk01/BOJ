//
// Created by woo-young Choi on 2022/11/09.
//

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define pii pair<int, int>
#define vii vector<pii>
#define ll long long

#define em emplace
#define emb emplace_back
#define range(x) x.begin(), x.end()
#define fastio iostream::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

vector<pair<int, pii>> edges;
vector<int> union_find;
int node_num, edge_num;
ll ans = 0;

int getParent(int x) {
    return union_find[x] == x ? x : getParent(union_find[x]);
}

bool isSameParent(int x, int y) {
    return getParent(x) == getParent(y);
}

void unionParent(int x, int y) {
    x = getParent(x);
    y = getParent(y);

    union_find[max(x, y)] = min(x, y);
}

void input() {
    cin >> node_num >> edge_num;
    union_find.resize(node_num + 1);
    iota(range(union_find), 0);

    edges.resize(edge_num);

    for (auto &edge: edges) {
        cin >> edge.second.first >> edge.second.second >> edge.first;
    }
}

void solve() {
    sort(range(edges));

    for (const auto &edge: edges) {
        int s = edge.second.first, e = edge.second.second;
        if (isSameParent(s, e)) continue;

        unionParent(s, e);
        ans += edge.first;
    }
}

void output() {
    cout << ans;
}

int main() {
    fastio

    input();
    solve();
    output();
}
