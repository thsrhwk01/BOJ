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

int n, k;

vector<pii> edges;

int main() {
    fastio;

    cin >> n >> k;

    rep(i, 1, n) {
        for (int j = i - 1; j > 0; j = j - 2) {
            if (edges.size() == k)
                break;
            edges.emb(i, j);
        }
    }

    if (edges.size() == k) {
        cout << "YES" << endl;
        rep(i, 0, k - 1) {
            cout << edges[i].first << ' ' << edges[i].second << endl;
        }
    } else {
        cout << "NO";
    }
}