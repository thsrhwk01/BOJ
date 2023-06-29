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

const int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1},
          dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int ans;

struct fish {
    int y, x, dir;
    bool isAlive = true;

    void set(int ny, int nx, int ndir) {
        y = ny;
        x = nx;
        dir = ndir;
    }

    void set(int ny, int nx) {
        y = ny;
        x = nx;
    }
};

struct state {
    // 0 = shark's state
    // {y, x, dir}
    array<fish, 17> fishInfo;

    // each block contains fish number
    array<array<int, 4>, 4> board;
};

state stateOriginal;

inline bool isOut(int y, int x) { return y < 0 or y >= 4 or x < 0 or x >= 4; }

void input() {
    int fishNum, fishDir;
    rep(i, 0, 3) {
        rep(j, 0, 3) {
            cin >> fishNum >> fishDir;

            stateOriginal.fishInfo[fishNum].set(i, j, fishDir - 1);
            stateOriginal.board[i][j] = fishNum;
        }
    }
}

void backtracking(state nowState, fish nowShark, int sharkSize, int step) {
    auto &nowBoard = nowState.board;
    auto &nowInfo = nowState.fishInfo;

    // fish moving
    rep(i, 1, 16) {
        auto &f = nowInfo[i];

        if (!f.isAlive)
            continue;

        int ny, nx;

        while (true) {
            ny = dy[f.dir] + f.y, nx = dx[f.dir] + f.x;

            if (!isOut(ny, nx) and nowBoard[ny][nx] != -1)
                break;

            f.dir = (f.dir + 1) % 8;
        }

        if (nowBoard[ny][nx] != 0) {
            nowInfo[nowBoard[ny][nx]].set(f.y, f.x);
        }

        swap(nowBoard[ny][nx], nowBoard[f.y][f.x]);

        f.y = ny;
        f.x = nx;
    }

    // shark moving
    nowBoard[nowShark.y][nowShark.x] = 0;
    while (true) {
        nowShark.y += dy[nowShark.dir];
        nowShark.x += dx[nowShark.dir];

        if (isOut(nowShark.y, nowShark.x))
            break;

        if (nowBoard[nowShark.y][nowShark.x] == 0 or !nowInfo[nowBoard[nowShark.y][nowShark.x]].isAlive)
            continue;

        int fishIdx = nowBoard[nowShark.y][nowShark.x];
        int prevDir = nowShark.dir;

        nowInfo[fishIdx].isAlive = false;
        nowBoard[nowShark.y][nowShark.x] = -1;
        nowShark.dir = nowInfo[fishIdx].dir;
        sharkSize += fishIdx;

        ans = max(ans, sharkSize);
        backtracking(nowState, nowShark, sharkSize, step+1);

        sharkSize -= fishIdx;
        nowShark.dir = prevDir;
        nowBoard[nowShark.y][nowShark.x] = fishIdx;
        nowInfo[fishIdx].isAlive = true;
    }
}

void solve() {
    // Initializing shark
    fish shark = stateOriginal.fishInfo[stateOriginal.board[0][0]];

    ans = stateOriginal.board[0][0];

    stateOriginal.fishInfo[stateOriginal.board[0][0]].isAlive = false;

    stateOriginal.board[0][0] = -1;

    backtracking(stateOriginal, shark, ans, 0);
}

void output() { cout << ans; }

int main() {
    fastio;

    input();
    solve();
    output();
}