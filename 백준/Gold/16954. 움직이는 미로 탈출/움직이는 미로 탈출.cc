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

bool ans;
string board[8];

int dy[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1},
    dx[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

inline bool isOut(int y, int x) { return y < 0 or y >= 8 or x < 0 or x >= 8; }

void input() {
    for (int i = 7; i >= 0; --i) {
        cin >> board[i];
    }
}

void solve() {
    queue<pii> q, nq, bq, bnq;
    array<array<bool, 8>, 8> isVisitedReset;

    for (auto &row : isVisitedReset)
        fill(all(row), false);

    rep(i, 0, 7) {
        rep(j, 0, 7) {
            if (board[i][j] == '#')
                bq.em(i, j);
        }
    }

    q.em(0, 0);

    while (!q.empty()) {
        auto isVisited = isVisitedReset;

        while (!q.empty()) {
            auto [y, x] = q.front();

            q.pop();

            if (board[y][x] == '#')
                continue;

            if (y == 7 and x == 7) {
                ans = true;
                return;
            }

            rep(i, 0, 8) {
                int ny = dy[i] + y, nx = dx[i] + x;

                if (isOut(ny, nx) or isVisited[ny][nx] or board[ny][nx] == '#')
                    continue;

                isVisited[ny][nx] = true;
                nq.em(ny, nx);
            }
        }

        while (!bq.empty()) {
            auto [y, x] = bq.front();

            bq.pop();

            board[y][x] = '.';

            if (isOut(y - 1, x))
                continue;

            board[y - 1][x] = '#';
            bnq.em(y - 1, x);
        }

        swap(bq, bnq);
        swap(q, nq);
    }
}

void output() { cout << ans; }

int main() {
    fastio;

    input();
    solve();
    output();
}