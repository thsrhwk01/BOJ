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

int n, parents[1'000'050], queryNum;

int findSet(int x) {
    return parents[x] == x ? x : parents[x] = findSet(parents[x]);
}

void unionSet(int x, int y) {
    x = findSet(x);
    y = findSet(y);

    parents[max(x, y)] = min(x, y);
}

bool isConnected(int x, int y) { return findSet(x) == findSet(y); }

void initialize() {
    rep(i, 0, n) { parents[i] = i; }
}

void solve() {
    cin >> n >> queryNum;

    initialize();

    int cmd, a, b;

    while (queryNum--) {
        cin >> cmd >> a >> b;
        switch (cmd) {
        case 0:
            // Union
            unionSet(a, b);
            break;
        case 1:
            cout << (isConnected(a, b) ? "YES" : "NO") << endl;
            break;
        }
    }
}

int main() {
    fastio;

    solve();
}
