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

int n, INF = 0x3f3f3f3f;

array<int, 1'000'005> arr, lis;

vi finder, ans;

void input() {
    cin >> n;

    rep(i, 1, n) { cin >> arr[i]; }
}

void solve() {
    fill(all(finder), INF);

    finder.emb(-1'000'000'100);

    rep(i, 1, n) {
        auto it = lower_bound(all(finder), arr[i]);

        lis[i] = it - finder.begin();

        if (it == finder.end())
            finder.emb(arr[i]);
        else
            *it = min(*it, arr[i]);
    }

    int cnt = *max_element(all(lis));

    for(int i = n; i > 0; --i) {
        if (lis[i] == cnt) {
            --cnt;
            ans.emb(arr[i]);
        }
    }

    reverse(all(ans));
}

void output() {
    cout << ans.size() << endl;
    for (auto &i : ans)
        cout << i << ' ';
}

int main() {
    fastio;

    input();
    solve();
    output();
}