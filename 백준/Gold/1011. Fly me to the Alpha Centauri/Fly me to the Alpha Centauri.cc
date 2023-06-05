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

ll x, y, ans;

void input() { cin >> x >> y; }

void solve() {
    y -= x;

    ll n = sqrt(y);

    if (n * n == y)
        ans = 2 * n - 1;
    else if (y > n * n && y <= n * n + n)
        ans = 2 * n;
    else
        ans = 2 * n + 1;
}

void output() { cout << ans << endl; }

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