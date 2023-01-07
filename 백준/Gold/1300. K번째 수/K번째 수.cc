//
// Created by woo-young Choi on 2023/01/08.
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

ll ans, n, k;

void input() {
    cin >> n >> k;
}

bool is_big(ll mid) {
    ll tmp = 0;

    for (ll i = 1; i <= n; ++i) {
        tmp += min(n, mid / i);

        if (tmp >= k) return true;
    }

    return tmp >= k;
}

ll bs(ll mm, ll MM) {
    if (MM < mm) return mm;

    ll mid = (MM + mm) / 2;

    if (is_big(mid))
        return bs(mm, mid - 1);
    else
        return bs(mid + 1, MM);
}

void solve() {
    ans = bs(1, n * n);
}

void output() {
    cout << ans;
}

int main() {
    fastio

    input();
    solve();
    output();
}