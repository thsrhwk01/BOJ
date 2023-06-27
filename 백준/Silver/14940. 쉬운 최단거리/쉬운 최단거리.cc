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

const int INF = 0x3f3f3f3f;

int n, m, board[1000][1000], dist[1000][1000];

int dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1};

pii startPos;

void input() {
    cin >> n >> m;

    rep(i, 0, n - 1) {
        rep(j, 0, m - 1) {
            cin >> board[i][j];

            if (board[i][j] == 2) {
                startPos = {i, j};
                board[i][j] = 1;
            }
        }
    }
}

inline bool isOut(int y, int x) { return y < 0 or y >= n or x < 0 or x >= m; }

void solve() {
    rep(i, 0, n - 1) {
        rep(j, 0, m - 1) { dist[i][j] = INF; }
    }

    dist[startPos.first][startPos.second] = 0;

    queue<pii> q;
    q.em(startPos);

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        int value = dist[y][x];

        rep(i, 0, 3) {
            int ny = dy[i] + y, nx = dx[i] + x;

            if (isOut(ny, nx) or board[ny][nx] == 0 or dist[ny][nx] != INF)
                continue;

            dist[ny][nx] = value + 1;
            q.em(ny, nx);
        }
    }
}

void output() {
    rep(i, 0, n - 1) {
        rep(j, 0, m - 1) {
            cout << (board[i][j] == 0 ? 0
                                      : (dist[i][j] != INF ? dist[i][j] : -1)) << ' ';
        }
        cout << endl;
    }
}

int main() {
    fastio;

    input();
    solve();
    output();
}