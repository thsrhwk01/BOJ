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

int n, m, ans;

int dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1}, board[100][100],
    result[100][100];

void input() {
    cin >> m >> n;

    char c;
    rep(i, 0, n - 1) {
        rep(j, 0, m - 1) {
            cin >> c;

            board[i][j] = c - '0';
        }
    }
}

inline bool isOut(int y, int x) { return y < 0 or y >= n or x < 0 or x >= m; }

void solve() {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                   greater<>>
        pq;

    rep(i, 0, n - 1) {
        rep(j, 0, m - 1) { result[i][j] = INF; }
    }

    // cost, y, x
    pq.em(0, 0, 0);
    result[0][0] = 0;
    
    while (!pq.empty()) {
        auto [cost, y, x] = pq.top();
        pq.pop();

        if (result[y][x] < cost)
            continue;

        if (y == n - 1 and x == m - 1)
            return;

        rep(i, 0, 3) {
            int ny = dy[i] + y, nx = dx[i] + x;

            if (isOut(ny, nx) or result[ny][nx] <= cost + board[ny][nx])
                continue;

            result[ny][nx] = cost + board[ny][nx];

            pq.em(cost + board[ny][nx], ny, nx);
        }
    }
}

void output() {
    cout << result[n - 1][m - 1];
}

int main() {
    fastio;

    input();
    solve();
    output();
}