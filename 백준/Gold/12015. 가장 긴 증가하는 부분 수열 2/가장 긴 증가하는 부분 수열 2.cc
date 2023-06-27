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

int n, arr[1'000'001], dp[1'000'001];

vi finder = {0};

void input() {
    cin >> n;

    rep(i, 1, n) { cin >> arr[i]; }
}

void solve() {
    rep(i, 1, n) {
        auto it = lower_bound(all(finder), arr[i]);

        dp[i] = it - finder.begin();

        if (it == finder.end()) finder.emb(arr[i]);
        else *it = min(*it, arr[i]);
    }
}

void output() {
    cout << *max_element(dp, dp + 1'000'001);
}

int main() {
    fastio;

    input();
    solve();
    output();
}