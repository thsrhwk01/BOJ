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

// right, up, left, down
pii dirs[4] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

// board: 0 : empty, 1 : snake, 2 : apple
int n, sec, board[101][101], turnTable[10001];

void input() {
    cin >> n;

    int appleNumber;
    cin >> appleNumber;

    int x, y;
    while (appleNumber--) {
        cin >> y >> x;

        board[y][x] = 2;
    }

    int turnNumber;
    cin >> turnNumber;

    int turnSec;
    char turnInfo;
    while (turnNumber--) {
        cin >> turnSec >> turnInfo;

        switch (turnInfo) {
        // left
        case 'L':
            turnTable[turnSec] = 1;
            break;
        case 'D':
            turnTable[turnSec] = -1;
        }
    }
}

inline bool isOut(int y, int x) { return (y < 1 || y > n || x < 1 || x > n); }

void solve() {
    board[1][1] = 1;
    deque<pii> dq;
    dq.emb(1, 1);

    // Start direction is right
    int dir = 0;
    while (true) {
        ++sec;
        auto [ny, nx] = dq.back();
        ny += dirs[dir].first;
        nx += dirs[dir].second;

        if (isOut(ny, nx) || board[ny][nx] == 1) return;

        if (board[ny][nx] != 2) {
            board[dq.front().first][dq.front().second] = 0;
            dq.pop_front();
        }

        board[ny][nx] = 1;
        dq.emb(ny, nx);

        dir = (4 + dir + turnTable[sec]) % 4;
    }
}

void output() { cout << sec; }

int main() {
    fastio;

    input();
    solve();
    output();
}