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

char boardOriginal[11][11], board[11][11];

int n, m;

// down, up, left, right
pii dirs[4] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

struct status {
    int ry, rx, by, bx, step;

    status(int ry, int rx, int by, int bx, int step)
        : ry(ry), rx(rx), by(by), bx(bx), step(step) {}

    bool isRedFirst(int dir) {
        switch (dir) {
        // down
        case 0:
            return (ry >= by);
        // up
        case 1:
            return (ry <= by);
        // left
        case 2:
            return (rx <= bx);
        // right
        default:
            return (rx >= bx);
        }
    }

    pii moveRed(int dir) {
        int y = ry, x = rx;

        while (true) {
            int ny = y + dirs[dir].first, nx = x + dirs[dir].second;

            if ((board[y][x] == 'O') ||
                (board[ny][nx] == 'B' || board[ny][nx] == '#'))
                break;

            y = ny;
            x = nx;
        }

        if (board[y][x] == '.')
            board[y][x] = 'R';

        return {y, x};
    }

    pii moveBlue(int dir) {
        int y = by, x = bx;

        while (true) {
            int ny = y + dirs[dir].first, nx = x + dirs[dir].second;

            if ((board[y][x] == 'O') ||
                (board[ny][nx] == 'R' || board[ny][nx] == '#'))
                break;

            y = ny;
            x = nx;
        }

        if (board[y][x] == '.')
            board[y][x] = 'B';

        return {y, x};
    }

    status move(int dir) {
        pii afterRed, afterBlue;
        if (isRedFirst(dir)) {
            afterRed = moveRed(dir);
            afterBlue = moveBlue(dir);
        } else {
            afterBlue = moveBlue(dir);
            afterRed = moveRed(dir);
        }

        board[afterRed.first][afterRed.second] =
            boardOriginal[afterRed.first][afterRed.second];

        board[afterBlue.first][afterBlue.second] =
            boardOriginal[afterBlue.first][afterBlue.second];

        return status(afterRed.first, afterRed.second, afterBlue.first,
                      afterBlue.second, step + 1);
    }
};

bool isNotMoved(status &l, status &r) {
    return l.ry == r.ry && l.rx == r.rx && l.by == r.by && l.bx == r.bx;
}

status initStatus(0, 0, 0, 0, 0);

void input() {
    cin >> n >> m;

    char block;
    rep(i, 0, n - 1) {
        rep(j, 0, m - 1) {
            cin >> block;

            switch (block) {
            case 'R':
                initStatus.ry = i;
                initStatus.rx = j;
                boardOriginal[i][j] = '.';
                break;

            case 'B':
                initStatus.by = i;
                initStatus.bx = j;
                boardOriginal[i][j] = '.';
                break;

            default:
                boardOriginal[i][j] = block;
            }
        }
    }
}

void solve() {
    rep(i, 0, n - 1) rep(j, 0, m - 1) board[i][j] = boardOriginal[i][j];

    queue<status> q;
    q.em(initStatus);

    while (!q.empty()) {
        auto now = q.front();
        q.pop();

        rep(i, 0, 3) {
            auto afterMove = now.move(i);

            if (isNotMoved(now, afterMove))
                continue;

            if (board[afterMove.by][afterMove.bx] == 'O')
                continue;

            if (board[afterMove.ry][afterMove.rx] == 'O') {
                cout << afterMove.step;
                return;
            }

            if (afterMove.step != 10)
                q.em(afterMove);
        }
    }

    cout << -1;
}

int main() {
    fastio;

    input();
    solve();
}