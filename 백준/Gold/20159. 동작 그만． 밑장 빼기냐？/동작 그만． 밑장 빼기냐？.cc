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

vector<ll> pref_sum;
vi cards;               //front = top, back = bottom

int n;
ll ans;

void input() {
    cin >> n;

    cards.resize(n);

    for (auto &card: cards) cin >> card;
}

void solve() {
    if (n == 2) {
        ans = max(cards[0], cards[1]);
        return;
    }
    pref_sum.resize(n + 2);

    pref_sum[0] = 0;
    pref_sum[1] = 0;

    for (int i = 0; i < n; ++i) pref_sum[i + 2] = pref_sum[i] + cards[i];

    // I will cheat on i-th turn
    // (n-1)-th turn => did not cheat
    for (int i = 0; i < n; ++i) {
        if (i & 1) { // odd turn  => Giving the bottom card to opposite
            ans = max(ans, pref_sum[i + 1] + pref_sum[n - 1] - pref_sum[i]);
        } else {     // even turn => Giving the bottom card to me
            ans = max(ans, pref_sum[i] + pref_sum[n + 1] - pref_sum[i + 1]);
        }
    }
}


/*
 * n = 6
 *
 * ' ' 0 1 2 3 4 5
 *
 * 0 0 3 2 5 2 1 3
 *
 * 0 1 2 3 4 5 6 7
 */

void output() {
    cout << ans;
}

int main() {
    fastio

    input();
    solve();
    output();
}
