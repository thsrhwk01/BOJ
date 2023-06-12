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

// up down left right
int dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1};

int n, m, ans = 0;

bool isVisited[300][300];

vvi board;

queue<pii> blocks;

void input() {
    cin >> n >> m;
    board.resize(n);

    rep(i, 0, n - 1) {
        auto &row = board[i];
        row.resize(m);

        rep(j, 0, m - 1) {
            cin >> row[j];

            if (row[j] != 0)
                blocks.em(i, j);
        }
    }
}

inline int counting(int y, int x) {
    int cnt = 0;
    rep(i, 0, 3) {
        if (board[dy[i] + y][dx[i] + x] == 0)
            ++cnt;
    }

    return cnt;
}

void melting() {
    auto tmp = board;
    queue<pii> nextq;

    while (!blocks.empty()) {
        auto [y, x] = blocks.front();
        blocks.pop();

        tmp[y][x] -= counting(y, x);

        if (tmp[y][x] <= 0)
            tmp[y][x] = 0;
        else
            nextq.em(y, x);
    }

    swap(board, tmp);
    swap(nextq, blocks);
}

bool checking() {
    int cnt = blocks.size();

    memset(isVisited, false, sizeof(isVisited));

    queue<pii> q;
    q.em(blocks.front());
    isVisited[q.front().first][q.front().second] = true;

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        --cnt;

        rep(i, 0, 3) {
            int ny = dy[i] + y, nx = dx[i] + x;

            if (board[ny][nx] > 0 && !isVisited[ny][nx]) {
                isVisited[ny][nx] = true;
                q.em(ny, nx);
            }
        }
    }

    return cnt != 0;
}

void solve() {
    while (true) {
        ++ans;
        melting();

        if (blocks.empty()) {
            ans = 0;
            return;
        }

        if (checking())
            return;
    }
}

void output() { cout << ans; }

int main() {
    fastio;

    input();
    solve();
    output();
}