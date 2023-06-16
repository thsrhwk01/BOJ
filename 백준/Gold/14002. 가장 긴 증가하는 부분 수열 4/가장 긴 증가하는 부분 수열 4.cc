#include <bits/stdc++.h>

using namespace std;

using ll  = long long;
using vi  = vector<int>;
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
    cout.tie(nullptr);                                                         \

const int INF = 0x3f3f3f3f;

int n, ans;

array<int, 1001> arr, lis, finder;

array<vi, 1001> lisCombi;

void input() {
    cin >> n;

    rep(i, 1, n) {
        cin >> arr[i];
    }
}

void solve() {
    fill(all(finder), INF);

    finder[0] = 0;

    rep(i, 1, n) {
        auto it = lower_bound(all(finder), arr[i]);

        lis[i] = it - finder.begin();
        lisCombi[lis[i]] = lisCombi[lis[i] - 1];
        lisCombi[lis[i]].emb(arr[i]);

        *it = min(*it, arr[i]);
        ans = max(ans, lis[i]);
    }
}

void output() {
    cout << ans << endl;
    for(auto &i: lisCombi[ans]) cout << i << ' ';
}

int main() {
    fastio;

    input();
    solve();
    output();
}