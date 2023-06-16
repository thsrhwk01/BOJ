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

int arr[2001];
bool dp[2001][2001];

int n;

void input() {
    cin >> n;

    rep(i, 1, n) cin >> arr[i];
}

void solve() {
    rep(i, 1, n) dp[i][i] = true;
    rep(i, 1, n - 1) if (arr[i] == arr[i + 1]) dp[i][i + 1] = true;
    for (int i = n - 2; i >= 1; --i) {
        rep(j, i + 2, n) {
            if (arr[i] == arr[j] and dp[i + 1][j - 1])
                dp[i][j] = true;
        }
    }
    
    int q;
    cin >> q;

    int from, to;
    while (q--) {
        cin >> from >> to;

        cout << dp[from][to] << endl;
    }
}

int main() {
    fastio;

    input();
    solve();
}