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

int dp[500'001];
int n, m, ans;

void input() { cin >> n >> m; }

void solve() {
    dp[0] = 1;
    dp[1] = 1;

    rep(i, 2, 500'000) {
        dp[i] = (dp[i - 2] + dp[i - 1]) % m;

        if (dp[i] == 0 and dp[i - 1] == 1) {
            ans = i + 1;
            return;
        }
    }
}

void output() { cout << n << ' ' << ans << endl; }

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