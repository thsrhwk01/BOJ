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

int n, k;

vii items;

int dp[105][100'005];

void input() {
    cin >> n >> k;

    items.emb(0, 0);

    rep(i, 1, n) {
        int w, v;
        cin >> w >> v;
        items.emb(w, v);
    }
}

void solve() {
    rep(i, 1, n) {
        auto [w, v] = items[i];

        rep(j, 1, k) {
            if (j < w)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + v);
        }
    }
}

void output() {
    int ans = 0;

    rep(i, 1, n) ans = max(ans, dp[i][k]);

    cout << ans;
}

int main() {
    fastio;

    input();
    solve();
    output();
}