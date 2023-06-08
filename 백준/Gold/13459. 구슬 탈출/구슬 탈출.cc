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

struct state {
    int ry, rx, by, bx, step;

    state(int ry, int rx, int by, int bx, int step)
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

    void moveRed(int dir) {
        while (true) {
            int ny = ry + dirs[dir].first, nx = rx + dirs[dir].second;

            if ((board[ry][rx] == 'O') ||
                (board[ny][nx] == 'B' || board[ny][nx] == '#'))
                break;

            ry = ny;
            rx = nx;
        }

        if (board[ry][rx] == '.')
            board[ry][rx] = 'R';
    }

    void moveBlue(int dir) {
        while (true) {
            int ny = by + dirs[dir].first, nx = bx + dirs[dir].second;

            if ((board[by][bx] == 'O') ||
                (board[ny][nx] == 'R' || board[ny][nx] == '#'))
                break;

            by = ny;
            bx = nx;
        }

        if (board[by][bx] == '.')
            board[by][bx] = 'B';
    }

    void resetBoard() {
        board[ry][rx] = boardOriginal[ry][rx];
        board[by][bx] = boardOriginal[by][bx];
    }

    void move(int dir) {
        ++step;

        if (isRedFirst(dir)) {
            moveRed(dir);
            moveBlue(dir);
        } else {
            moveBlue(dir);
            moveRed(dir);
        }

        resetBoard();
    }
};

bool isNotMoved(state &l, state &r) {
    return l.ry == r.ry && l.rx == r.rx && l.by == r.by && l.bx == r.bx;
}

state initStatus(0, 0, 0, 0, 0);

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

    queue<state> q;
    q.em(initStatus);

    while (!q.empty()) {
        auto nowState = q.front();
        q.pop();

        rep(i, 0, 3) {
            auto nextState = nowState;

            nextState.move(i);

            if (isNotMoved(nowState, nextState))
                continue;

            if (board[nextState.by][nextState.bx] == 'O')
                continue;

            if (board[nextState.ry][nextState.rx] == 'O') {
                cout << 1;
                return;
            }

            if (nextState.step != 10)
                q.em(nextState);
        }
    }

    cout << 0;
}

int main() {
    fastio;

    input();
    solve();
}