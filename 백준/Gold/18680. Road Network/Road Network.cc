#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

#define endl '\n'
#define em emplace
#define emb emplace_back
#define all(x) x.begin(), x.end()
#define rep(i, from, to) for (int i = from; i <= to; ++i)
#define fastio                                                                 \
    iostream::sync_with_stdio(false);                                          \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);

int n, ans, start, last, costMax;

bool isVisited[10'004];

vvi edges;

void input() {
    cin >> n;

    edges.clear();
    edges.resize(n + 4);

    int a, b;
    rep(i, 2, n) {
        cin >> a >> b;

        edges[a].emb(b);
        edges[b].emb(a);
    }
}

void dfs(int node, int cost, int &ending) {
    isVisited[node] = true;
    if (cost > costMax) {
        costMax = cost;
        ending = node;
    }

    for (const auto &nextNode : edges[node]) {
        if(!isVisited[nextNode]) dfs(nextNode, cost + 1, ending);
    }
}

void solve() {
    memset(isVisited, 0, sizeof(isVisited));
    costMax = -1;

    dfs(1, 0, start);

    memset(isVisited, 0, sizeof(isVisited));
    costMax = -1;

    dfs(start, 0, last);

    ans = n - 1 - costMax;
}

void output() {
    cout << ans << endl;
}

int main() {
    fastio;

    int t;
    cin >> t;

    while (t--) {
        input();
        solve();
        output();
    }
}