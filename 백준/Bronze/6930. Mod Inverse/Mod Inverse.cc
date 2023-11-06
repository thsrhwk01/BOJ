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

int main() {
    fastio;

    int x, m, ans = 0;

    cin >> x >> m;

    rep(i, 1, m) {
        if ((x * i) % m == 1) {
            ans = i;
            break;
        }
    }

    if (ans == 0) {
        cout << "No such integer exists.";
    } else {
        cout << ans;
    }
}