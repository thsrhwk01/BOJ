//
// Created by woo-young Choi on 2023/01/12.
//

#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<pii>;
using ll = long long;

#define endl '\n'
#define em emplace
#define emb emplace_back
#define all(x) x.begin(), x.end()
#define fastio iostream::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

vector<vector<ll>> dp(31, vector<ll>(31));

int n;

void solve() {
    dp[0][0] = 0;

    for (int i = 1; i < 31; ++i) {
        dp[i][0] = 1;

        for (int j = 1; j < 31; ++j) {
            if (j > i) continue;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
}

int main() {
    fastio

    solve();

    while (cin >> n && n != 0) cout << dp[n][n] << endl;
}
