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

    int cnts[4] {}, ans = 0, n;

    cin >> n;

    rep(i, 1, n) {
        int tmp;
        cin >> tmp;

        cnts[tmp]++;
    }

    int mm;

    mm = min(cnts[0], cnts[3]);
    ans += 3 * mm;
    cnts[0] -= mm;
    cnts[3] -= mm;

    mm = min(cnts[1], cnts[2]);
    ans += 3 * mm;
    cnts[1] -= mm;
    cnts[2] -= mm;

    mm = min(cnts[0], cnts[2]);
    ans += 2 * mm;
    cnts[0] -= mm;
    cnts[2] -= mm;

    mm = min(cnts[1], cnts[3]);
    ans += 2 * mm;
    cnts[1] -= mm;
    cnts[3] -= mm;

    mm = min(cnts[0], cnts[1]);
    ans += 1 * mm;
    cnts[0] -= mm;
    cnts[1] -= mm;

    mm = min(cnts[2], cnts[3]);
    ans += 1 * mm;
    cnts[2] -= mm;
    cnts[3] -= mm;

    cout << ans;
}