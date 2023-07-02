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

int counter[501][501][26];
vector<string> board, tile;

int n, m, k, ans;

void input() {
    cin >> n >> m >> k;

    board.resize(n);

    for (auto &row : board)
        cin >> row;
}

void solve() {
    for (int i = 0; i < n; i += k) {
        for (int j = 0; j < m; j += k) {
            for (int y = i; y < i + k; ++y) {
                for (int x = j; x < j + k; ++x) {
                    counter[y - i][x - j][board[y][x] - 'A']++;
                }
            }
        }
    }

    const int sz = (n / k) * (m / k);
    rep(i, 0, k - 1) {
        tile.emb();
        rep(j, 0, k - 1) {
            int cnt = 0;
            char ch = 'A';

            rep(l, 0, 25) {
                if (counter[i][j][l] > cnt) {
                    cnt = counter[i][j][l];
                    ch = l + 'A';
                }
            }

            ans += sz - cnt;

            tile.back() += ch;
        }
    }
}

void output() {
    cout << ans << endl;

    rep(i, 0, n - 1) {
        rep(j, 0, m / k - 1) cout << tile[i % k];
        cout << endl;
    }
}

int main() {
    fastio;

    input();
    solve();
    output();
}
