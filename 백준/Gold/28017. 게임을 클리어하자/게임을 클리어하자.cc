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

unsigned long long gameCount, weaponCount, weaponInfo[505][505], dp[505][505];

void input() {
    cin >> gameCount >> weaponCount;

    rep(gameNum, 1, gameCount) {
        rep(weaponNum, 1, weaponCount) {
            cin >> weaponInfo[gameNum][weaponNum];
        }
    }
}

void solve() {
    rep(gameNum, 1, gameCount) {
        rep(weaponNum, 1, weaponCount) {
            unsigned long long temp = 0xffffffffffffffff;

            rep(i, 1, weaponCount) {
                if (i == weaponNum) continue;
                temp = min(temp, dp[gameNum - 1][i]);
            }

            dp[gameNum][weaponNum] = temp + weaponInfo[gameNum][weaponNum];
        }
    }
}

void output() {
    cout << *min_element(dp[gameCount] + 1, dp[gameCount] + weaponCount + 1);
}

int main() {
    fastio;

    input();
    solve();
    output();
}