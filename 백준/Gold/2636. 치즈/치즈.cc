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

// air = 2, cheese = 1, vacuum = 0;

array<array<int, 100>, 100> board;

// up down left right
int dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1};

int n, m, cheeseCnt, sec, cheeseCntLast;

queue<pii> meltQ, airQ;

void input() {
    cin >> n >> m;

    rep(y, 0, n - 1) {
        rep(x, 0, m - 1) {
            cin >> board[y][x];

            if (board[y][x] == 1)
                ++cheeseCnt;
        }
    }
}
// check out of bound
inline bool isOut(int y, int x) { return y < 0 or y >= n or x < 0 or x >= m; }

void fillingAir() {
    while (!airQ.empty()) {
        auto [y, x] = airQ.front();
        airQ.pop();

        if (board[y][x] != 0)
            continue;
        board[y][x] = 2;

        rep(i, 0, 3) {
            int ny = dy[i] + y, nx = dx[i] + x;

            if (isOut(ny, nx) or board[ny][nx] == 2)
                continue;

            if (board[ny][nx] == 1) {
                meltQ.em(ny, nx);
                continue;
            }

            airQ.em(ny, nx);
        }
    }
}

void meltingCheese() {
    while (!meltQ.empty()) {
        auto [y, x] = meltQ.front();
        meltQ.pop();

        if (board[y][x] != 1)
            continue;
        board[y][x] = 0;
        --cheeseCnt;

        airQ.em(y, x);
    }
}

void solve() {
    airQ.em(0, 0);

    while (cheeseCnt > 0) {
        cheeseCntLast = cheeseCnt;
        ++sec;
        fillingAir();
        meltingCheese();
    }
}

void output() {
    cout << sec << endl << cheeseCntLast;
}

int main() {
    fastio;

    input();
    solve();
    output();
}