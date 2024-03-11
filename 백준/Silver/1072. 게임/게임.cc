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
#define fastio                        \
    iostream::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

int main() {
    fastio;

    ll x, y;

    cin >> x >> y;

    int z = y * 100 / x;

    if (z >= 99) {
        cout << -1;
        return 0;
    }

    ll l = 0, r = 0x3f3f3f3f3f3f3f3f;

    while (l + 1 < r) {
        ll mid = (l + r) / 2;

        int tz = double(y + mid) / double(x + mid) * 100;

        if (tz > z) {
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << r;
}