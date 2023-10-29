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

    int n, k, ans = 0;
    cin >> n >> k;

    int now = -0x3f3f3f3f;
    rep(i, 1, n) {
        int tmp;
        cin >> tmp;

        if (now + k < tmp) {
            now = tmp;
            ++ans;
        }
    }

    cout << ans;
    return 0;
}