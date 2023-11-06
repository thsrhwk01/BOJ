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

ll power(ll x, ll p, ll m) {
    ll ret = 1;

    while (p) {
        if (p & 1) {
            ret *= x;
            ret %= m;
        }

        x *= x;
        x %= m;
        p /= 2;
    }
    
    return ret;
}

int main() {
    fastio;

    ll n, k, m = 1'000'000'007;
    cin >> n >> k;

    ll a = 1, b = 1;

    rep(i, 1, n) {
        a *= i;
        a %= m;
    }

    rep(i, 1, n - k) {
        b *= i;
        b %= m;
    }

    rep(i, 1, k) {
        b *= i;
        b %= m;
    }

    b = power(b, m - 2, m) % m;

    cout << (a * b) % m;
}