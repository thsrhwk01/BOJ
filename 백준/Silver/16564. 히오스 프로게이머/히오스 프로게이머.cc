//
// Created by woo-young Choi on 2022/12/31.
//

//히오스... 프로게이머..?

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

vi levels;
int n, k, ans;

void input() {
    cin >> n >> k;

    levels.resize(n);

    for (auto &level: levels) cin >> level;
}

int bn(int start, int last) {
    if (last - start == 0 or last - start == 1) return start;

    int half = (ll(start) + ll(last)) / 2;
    auto it = lower_bound(all(levels), half);
    ll used = half * (it - levels.begin()) - accumulate(levels.begin(), it, 0ll);
    ll remaining = ll(k) - used;

    if (remaining == 0) return half;
    else if (remaining > 0) start = half;
    else last = half;

    return bn(start, last);
}

void solve() {
    sort(all(levels));

    ans = bn(0, 2'000'000'001);
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
