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

int x, y;

void input() { cin >> x >> y; }

void solve() {}

void output() { cout << (x > 0 ? (y > 0 ? 1 : 4) : (y > 0 ? 2 : 3)); }

int main() {
    fastio;

    input();
    solve();
    output();
}
