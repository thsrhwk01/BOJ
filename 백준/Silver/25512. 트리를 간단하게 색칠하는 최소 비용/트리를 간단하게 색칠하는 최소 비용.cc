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

int main() {
    fastio;

    pii costs[100'003];
    vi edges[100'003];

    int n;
    cin >> n;

    rep(i, 1, n - 1) {
        int from, to;
        cin >> from >> to;

        edges[from].emb(to);
    }

    rep(i, 0, n - 1) {
        int a, b;
        cin >> a >> b;

        costs[i] = make_pair(a, b);
    }

    queue<pair<int, bool>> q;
    q.em(0, true);

    ll ans1 = 0, ans2 = 0;

    while (!q.empty()) {
        auto [node, color] = q.front();
        q.pop();

        if (color) {
            ans1 += costs[node].first;
            ans2 += costs[node].second;
        } else {
            ans1 += costs[node].second;
            ans2 += costs[node].first;
        }

        for (auto nextNode : edges[node]) {
            q.em(nextNode, !color);
        }
    }

    cout << min(ans1, ans2);

    return 0;
}