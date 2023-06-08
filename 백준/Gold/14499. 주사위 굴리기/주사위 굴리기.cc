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

// nothing, east, west, north, south
int dy[5] = {0, 0, 0, -1, 1};
int dx[5] = {0, 1, -1, 0, 0};

int n, m, k, board[20][20];

inline bool isOut(int y, int x) { return y < 0 || y >= n || x < 0 || x >= m; }

struct myDice {
    int top = 0, bottom = 0, east = 0, west = 0, north = 0, south = 0, y, x;

    void switching(int dir) {
        int tmp = top;
        switch (dir) {
        case 1:
            // East
            top = west;
            west = bottom;
            bottom = east;
            east = tmp;
            break;

        case 2:
            // West
            top = east;
            east = bottom;
            bottom = west;
            west = tmp;
            break;

        case 3:
            // North
            top = south;
            south = bottom;
            bottom = north;
            north = tmp;
            break;

        case 4:
            // South
            top = north;
            north = bottom;
            bottom = south;
            south = tmp;
            break;
        }
    }

    void roll(int dir) {
        int ny = dy[dir] + y, nx = dx[dir] + x;

        if (isOut(ny, nx))
            return;

        y = ny, x = nx;

        switching(dir);

        if (board[y][x] == 0)
            board[y][x] = bottom;
        else {
            bottom = board[y][x];
            board[y][x] = 0;
        }

        cout << top << endl;
    }
};

myDice dice;

void input() {
    cin >> n >> m >> dice.y >> dice.x >> k;

    rep(i, 0, n - 1) {
        rep(j, 0, m - 1) { cin >> board[i][j]; }
    }
}

void solve() {
    int query;
    while (k--) {
        cin >> query;

        dice.roll(query);
    }
}

int main() {
    fastio;

    input();
    solve();
}