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

int n, m, board[500][500];

ll dp[500][500];

int dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1};

void input() {
    cin >> n >> m;

    rep(i, 0, n - 1) {
        rep(j, 0, m - 1) {
            dp[i][j] = -1;
            cin >> board[i][j];
        }
    }
}

inline bool isOut(int y, int x) { return y < 0 or y >= n or x < 0 or x >= m; }

ll dfs(int y, int x) {
    if (dp[y][x] != -1)
        return dp[y][x];

    dp[y][x] = 0;

    rep(i, 0, 3) {
        int ny = dy[i] + y, nx = dx[i] + x;

        if (isOut(ny, nx) or board[y][x] <= board[ny][nx])
            continue;

        dp[y][x] += dfs(ny, nx);
    }

    return dp[y][x];
}

void solve() {
    dp[n - 1][m - 1] = 1;
    dfs(0, 0);
}

void output() {
    cout << dp[0][0];
}

int main() {
    fastio;

    input();
    solve();
    output();
}