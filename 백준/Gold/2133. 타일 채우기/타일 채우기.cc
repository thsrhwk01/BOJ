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

ll dp[31];

void input() { cin >> n; }

void solve() {
    dp[0] = 1;
    dp[2] = 3;

    for (int i = 4; i <= 30; i += 2) {
        int now = i - 2;

        dp[i] += dp[now] * dp[i - now];
        
        while (now >= 0) {
            now -= 2;

            dp[i] += dp[now] * 2;
        }
    }
}

void output() {
    cout << dp[n];
}

int main() {
    fastio;

    input();
    solve();
    output();
}