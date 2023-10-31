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

vector<ll> tower(100'005);
vector<pair<ll, ll>> difference(100'005);

inline ll sub(ll left, ll right) {
    return (left - right > 0 ? left - right : 0);
}

int main() {
    fastio;

    ll n, x;
    cin >> n >> x;

    rep(i, 1, n) { cin >> tower[i]; }
    tower[0] = -0x3f3f3f3f3f3f3f3f;
    tower[n + 1] = -0x3f3f3f3f3f3f3f3f;

    ll ans = 0x3f3f3f3f3f3f3f3f;

    rep(i, 1, n) {
        ll l = tower[i - 1], m = tower[i], r = tower[i + 1], temp;

        if (m >= l and m >= r) {
            temp = sub(max(l, r) + x, m);
        } else if (m < l and m < r) {
            temp = sub(m + x, l) + sub(m + x, r);
        } else {
            temp = sub(x + min(l, r), m);
            temp += sub(m + temp + x, max(l, r));
        }

        ans = min(ans, temp);
    }

    cout << ans;
}