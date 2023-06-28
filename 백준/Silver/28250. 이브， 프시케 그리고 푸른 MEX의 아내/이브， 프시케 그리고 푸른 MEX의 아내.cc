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

ll ans;

int arr[3];

void solve() {
    cin >> n;

    int x;
    while (n--) {
        cin >> x;

        switch (x) {
        case 0:
            ans += arr[1] * 2 + (arr[0] + arr[2]);
            arr[0]++;
            break;

        case 1:
            ans += arr[0] * 2;
            arr[1]++;
            break;

        default:
            ans += arr[0];
            arr[2]++;
            break;
        }
    }

    cout << ans;
}

int main() {
    fastio;

    solve();
}
