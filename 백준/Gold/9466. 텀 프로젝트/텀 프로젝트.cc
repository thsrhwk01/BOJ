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

int n;

int target[100'001], group[100'001];

void input() {
    cin >> n;

    rep(i, 1, n) { cin >> target[i]; }
}

int dfs(int node) {
    group[node] = -1;

    int nodeNext = target[node];

    if (group[nodeNext] == -1)
        group[node] = nodeNext;
    else if (group[nodeNext] == 0)
        group[node] = dfs(nodeNext);
    else
        return group[node] = -2;

    if (group[node] == node)
        return -2;

    return group[node];
}

void solve() {
    memset(group, 0, sizeof(group));

    rep(i, 1, n) {
        if (group[i] == 0)
            dfs(i);
    }
}

void output() {
    int cnt = 0;
    rep(i, 1, n) {
        if (group[i] == -2)
            ++cnt;
    }

    cout << cnt << endl;
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