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

vector<pair<double, double>> points;

struct edge {
    int s, e;
    double cost;

    edge(int s, int e, double cost) : s(s), e(e), cost(cost) {}

    bool operator<(const edge &left) const {
        return cost < left.cost;
    }
};

int n;
double ans;

vector<int> finding;
vector<edge> edges;

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
    cin >> n;
    finding.resize(n);
    points.resize(n);

    iota(range(finding), 0);

    for (auto &p: points) {
        cin >> p.first >> p.second;
    }
}

void solve() {
    double xdist, ydist, dist;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            xdist = points[i].first - points[j].first;
            ydist = points[i].second - points[j].second;
            dist = sqrt(xdist * xdist + ydist * ydist);

            edges.emb(i, j, dist);
        }
    }

    sort(range(edges));

    for (const auto &ed: edges) {
        if (isSameParent(ed.s, ed.e)) continue;

        unionParent(ed.s, ed.e);
        ans += ed.cost;
    }
}

void output() {
    cout.precision(2);
    cout << fixed << ans;
}

int main() {
    fastio

    input();
    solve();
    output();
}
