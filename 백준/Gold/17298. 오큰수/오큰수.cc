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

int n;

int arr[1'000'001], res[1'000'001];

void input() {
    cin >> n;

    rep(i, 1, n) { cin >> arr[i]; }
}

void solve() {
    stack<int> stk;

    for (int i = n; i > 0; --i) {
        while (!stk.empty()) {
            if (stk.top() <= arr[i])
                stk.pop();
            else
                break;
        }

        if (!stk.empty()) {
            res[i] = stk.top();
        } else {
            res[i] = -1;
        }

        stk.em(arr[i]);
    }
}

void output() {
    rep(i, 1, n) cout << res[i] << ' ';
}

int main() {
    fastio;

    input();
    solve();
    output();
}