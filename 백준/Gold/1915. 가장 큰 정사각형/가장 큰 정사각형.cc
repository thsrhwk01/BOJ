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

int n, m, ans, board[1001][1001], dp[1001][1001];

void input() {
    cin >> n >> m;

    char c;
    rep(i, 1, n) {
        rep(j, 1, m) {
            cin >> c;

            if (c == '1')
                board[i][j] = 1;
        }
    }
}

void solve() {
    rep(i, 1, n) {
        rep(j, 1, m) {
            if (board[i][j] == 1)
                dp[i][j] =
                    min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;

            ans = max(ans, dp[i][j]);
        }
    }
}

void output() {
    cout << ans * ans;
}

int main() {
    fastio;

    input();
    solve();
    output();
}