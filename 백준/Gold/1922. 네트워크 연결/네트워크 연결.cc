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

struct edge {
    int s, e, cost;

    bool operator< (const edge &left) const {
        return cost < left.cost;
    }
};

vector<int> finding;
vector<edge> edges;

int n, e;
ll ans = 0;

int getParent(int x) {
    return finding[x] == x ? x : getParent(finding[x]);
}

bool isSameParent(int x, int y) {
    return getParent(x) == getParent(y);
}

void unionParent(int x, int y) {
    x = getParent(x);
    y = getParent(y);

    finding[max(x, y)] = min(x, y);
}

void input() {
    cin >> n >> e;

    finding.resize(n + 1);
    iota(range(finding), 0);

    edges.resize(e);

    for (auto &ed: edges) {
        cin >> ed.s >> ed.e >> ed.cost;
    }
}

void solve() {
    sort(range(edges));

    for (const auto &ed: edges) {
        if (isSameParent(ed.s, ed.e)) continue;

        unionParent(ed.s, ed.e);
        ans += ed.cost;
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
