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

ll n, INF = 0x3f3f3f3f3f3f3f3fLL;

array<ll, 1'000'005> arr, lis, lisTracker, finder, finderIdx;

vector<ll> ans;

void input() {
    cin >> n;

    rep(i, 1, n) {
        cin >> arr[i];
        arr[i] += 1'000'000'001;
    }
}

void solve() {
    fill(all(finder), INF);

    finder[0] = 0;

    rep(i, 1, n) {
        auto it = lower_bound(all(finder), arr[i]);
        int j = it - finder.begin();

        lis[i] = j;
        lisTracker[i] = finderIdx[j - 1];

        // finder 갱신
        if (*it > arr[i]) {
            *it = arr[i];
            finderIdx[j] = i;
        }
    }

    auto i = max_element(all(lis)) - lis.begin();
    while (i > 0) {
        ans.emb(arr[i]);
        i = lisTracker[i];
    }

    reverse(all(ans));
}

void output() {
    cout << ans.size() << endl;
    for (auto &i: ans) cout << i - 1'000'000'001 << ' ';
}

int main() {
    fastio;

    input();
    solve();
    output();
}