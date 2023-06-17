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

string a, b, ans;

int dp[1001][1001];

void input() { cin >> a >> b; }

void solve() {
    int n = a.size(), m = b.size();

    rep(i, 1, n) {
        rep(j, 1, m) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    while (n > 0 and m > 0) {
        if (a[n - 1] == b[m - 1]) {
            ans += a[n - 1];
            --n;
            --m;

            continue;
        }

        if (dp[n - 1][m] > dp[n][m - 1])
            --n;
        else
            --m;
    }

    reverse(all(ans));
}

void output() {
    cout << dp[a.size()][b.size()] << endl << ans;
}

int main() {
    fastio;

    input();
    solve();
    output();
}