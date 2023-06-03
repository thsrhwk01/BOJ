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

pii dirs[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int n, m;

vvi boardOriginal;

vii wallPos;
queue<pii> virusPos;

int ans = 0;

void input() {
    cin >> n >> m;

    boardOriginal.resize(n);

    rep(i, 0, n - 1) {
        auto &row = boardOriginal[i];
        row.resize(m);

        rep(j, 0, m - 1) {
            cin >> row[j];

            if (row[j] == 2)
                virusPos.em(i, j);

            if (row[j] == 0)
                wallPos.emb(i, j);
        }
    }
}

void bfs(vvi board) {
    auto q = virusPos;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        rep(i, 0, 3) {
            int nx = x + dirs[i].first;
            int ny = y + dirs[i].second;

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            if (board[nx][ny] == 0) {
                board[nx][ny] = 2;
                q.em(nx, ny);
            }
        }
    }

    int cnt = 0;

    for (auto &row : board) {
        for (auto &elem : row) {
            if (elem == 0)
                ++cnt;
        }
    }

    ans = max(ans, cnt);
}

void solve() {
    int w = wallPos.size() - 1;

    rep(i, 0, w) {
        boardOriginal[wallPos[i].first][wallPos[i].second] = 1;

        rep(j, i + 1, w) {
            boardOriginal[wallPos[j].first][wallPos[j].second] = 1;

            rep(k, j + 1, w) {
                boardOriginal[wallPos[k].first][wallPos[k].second] = 1;

                bfs(boardOriginal);

                boardOriginal[wallPos[k].first][wallPos[k].second] = 0;
            }

            boardOriginal[wallPos[j].first][wallPos[j].second] = 0;
        }

        boardOriginal[wallPos[i].first][wallPos[i].second] = 0;
    }
}

void output() { cout << ans; }

int main() {
    fastio;

    input();
    solve();
    output();
}