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

array<array<int, 50>, 50> board;

int n, m, sec;

// up down left right
int dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1};

// cleaner position
pii cleanerUpper = {-1, -1}, cleanerLower;

void input() {
    cin >> n >> m >> sec;

    rep(i, 0, n - 1) {
        rep(j, 0, m - 1) {
            cin >> board[i][j];

            if (board[i][j] == -1) {
                if (cleanerUpper.first == -1)
                    cleanerUpper = make_pair(i, j);
                else
                    cleanerLower = make_pair(i, j);
            }
        }
    }
}

inline bool isOut(int y, int x) {
    return (y < 0 or y >= n or x < 0 or x >= m) or (board[y][x] == -1);
}

void diffusion() {
    auto temp = board;
    rep(y, 0, n - 1) {
        rep(x, 0, m - 1) {
            if (board[y][x] < 5)
                continue;

            int amount = board[y][x] / 5;

            rep(i, 0, 3) {
                int ny = dy[i] + y, nx = dx[i] + x;
                if (isOut(ny, nx))
                    continue;

                temp[ny][nx] += amount;
                temp[y][x] -= amount;
            }
        }
    }

    swap(board, temp);
}

void cleanUpper() {
    auto [y, x] = cleanerUpper;

    --y;

    while (y > 0) {
        --y;

        board[y + 1][x] = board[y][x];
    }

    while (x < m - 1) {
        ++x;
        board[y][x - 1] = board[y][x];
    }

    while (y < cleanerUpper.first) {
        ++y;
        board[y - 1][x] = board[y][x];
    }

    while (x > cleanerUpper.second + 1) {
        --x;
        board[y][x + 1] = board[y][x];
    }
    
    board[y][x] = 0;
}

void cleanLower() {
    auto [y,x] = cleanerLower;

    ++y;

    while (y < n - 1) {
        ++y;

        board[y-1][x] = board[y][x];
    }

    while (x < m - 1) {
        ++x;
        board[y][x - 1] = board[y][x];
    }

    while (y > cleanerLower.first) {
        --y;

        board[y + 1][x] = board[y][x];
    }

    while (x > cleanerUpper.second + 1) {
        --x;
        board[y][x + 1] = board[y][x];
    }

    board[y][x] = 0;
}

void solve() {
    while (sec--) {
        diffusion();
        cleanUpper();
        cleanLower();
    }
}

void output() {
    int sum = 0;
    rep(i, 0, n - 1) {
        rep(j, 0, m - 1) {
            if (board[i][j] > 0) sum += board[i][j];
        }
    }

    cout << sum;
}

int main() {
    fastio;

    input();
    solve();
    output();
}