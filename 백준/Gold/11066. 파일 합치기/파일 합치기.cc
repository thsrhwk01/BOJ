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

const ll INF = 0x3f3f3f3f3f3f3f3f;

ll dp[501][501], prefixSum[501];

int pages[501], n;

void input() {
    cin >> n;

    rep(i, 1, n) {
        cin >> pages[i];
        prefixSum[i] = prefixSum[i - 1] + pages[i];
    }
}

void solve() {
    rep(i, 1, n) {
        rep(j, 1, n - i) {
            dp[j][i + j] = INF;

            rep(k, j, i + j - 1) {
                dp[j][i + j] =
                    min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] +
                                          prefixSum[i + j] - prefixSum[j - 1]);
            }
        }
    }
}

void output() { cout << dp[1][n] << endl; }

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