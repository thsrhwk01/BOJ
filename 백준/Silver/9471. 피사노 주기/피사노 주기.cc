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

int n, m, ans;

void input() { cin >> n >> m; }

void solve() {
    ans = 2;
    int a = 1, b = 1;

    while (true) {
        ++ans;
        int c = (a + b) % m;

        if (c == 0 and b == 1)
            return;

        a = b;
        b = c;
    }
}

void output() {
    cout << n << ' ' << ans << endl;
}

int main() {
    fastio;

    int t;
    cin >> t;

    while (t--) {
        input();
        solve();
        output();
    }
}