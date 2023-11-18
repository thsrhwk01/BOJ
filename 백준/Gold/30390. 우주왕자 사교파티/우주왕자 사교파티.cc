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

ll gcd(ll a, ll b) {
    if (a % b == 0)
        return b;

    return gcd(b, a % b);
}

int main() {
    fastio;

    ll a, b, k;

    cin >> a >> b >> k;
    if (a > b)
        swap(a, b);

    ll x = a + b;

    // 아예 한쪽에 몰아줄 수 있을 때
    if (min(a, b) <= k) {
        cout << x;
        return 0;
    }

    ll ans = 0;

    for (ll i = 1; i <= sqrt(x); ++i) {
        if (x % i == 0) {
            ll div = a / i;

            if (min(abs(a - div * i), abs(a - (div + 1) * i)) <= k) {
                // cout << i << endl;
                ans = max(ans, i);
            }

            ll j = x / i;
            div = a / j;

            if (min(abs(a - div * j), abs(a - (div + 1) * j)) <= k) {
                // cout << j << endl;
                ans = max(ans, j);
            }
        }
    }

    cout << ans;
    return 0;
}