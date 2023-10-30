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

    int n, m;

    cin >> n >> m;

    vi ls;

    rep(i, 1, n) {
        int k;
        cin >> k;

        rep(j, 1, k) {
            int tmp;
            cin >> tmp;

            if (j == 1 or j == k) {
                ls.emb(tmp);
            }
        }
    }

    sort(all(ls));
    
    cout << ls[n - 1];
}