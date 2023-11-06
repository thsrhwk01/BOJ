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

ll power(ll i, ll p, ll mod) {
    ll ret = 1;

    while (p) {
        if (p & 1) {
            ret *= i;
            ret %= mod;
        }

        i *= i;
        i %= mod;
        p /= 2;
    }

    return ret;
}

int main() {
    fastio;

    ll a, b, mod = 1e9 + 7;
    cin >> a >> b;

    if (a == 1) {
        cout << (a * b) % mod;
        return 0;
    }

    ll x, y;
    x = power(a, b, mod) - 1;
    y = a - 1;

    y = power(y, mod - 2, mod);

    cout << (x * y) % mod;
}