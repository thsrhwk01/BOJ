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

int X1, X2, X3;
int Y1, Y2, Y3, signedArea;

void input() {
    cin >> X1 >> Y1 >> X2 >> Y2 >> X3 >> Y3;
}

void solve() {
    signedArea = X1 * Y2 + X2 * Y3 + X3 * Y1 - X2 * Y1 - X3 * Y2 - X1 * Y3;
}

void output() {
    if (signedArea > 0) cout << 1;
    else if (signedArea == 0) cout << 0;
    else cout << -1;
}

int main() {
    fastio;

    input();
    solve();
    output();
}