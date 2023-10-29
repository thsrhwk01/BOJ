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

ll n, k, ans = 0, mod = 1e9 + 7;
vector<ll> vec, pos, dp;

void input() {
    cin >> n >> k;
    vec.resize(n + 1);
    dp.resize(n + 1);
    rep(i, 1, n) cin >> vec[i];
}

void solve() {
    pos = vec;
    pos[n] = k;

    for (int i = n; i >= 1; --i) {

        if (pos[i] != vec[i]) {
            set<int> tmp = {1, 2, 3};

            tmp.erase(pos[i]);
            tmp.erase(vec[i]);

            pos[i - 1] = *tmp.begin();
        } else {
            pos[i - 1] = pos[i];
        }
    }

    dp[0] = 1;
    rep(i, 1, n) {
        dp[i] = (dp[i - 1] * 2) % mod;

        if (pos[i] != vec[i]) {
            ans = (ans + dp[i - 1]) % mod;
            // cout << i << ' ' << dp[i] << endl;
        }
    }
}

void output() { cout << ans; }

int main() {
    fastio;

    input();
    solve();
    output();
}