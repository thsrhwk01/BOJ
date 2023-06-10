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

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

int n, board[126][126], result[126][126], t = 1;

void input() {
    rep(i, 1, n) {
        rep(j, 1, n) { cin >> board[i][j]; }
    }
}

inline bool isOut(int y, int x) { return y < 1 || y > n || x < 1 || x > n; }

void solve() {
    memset(result, INF, sizeof(result));

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                   greater<>>
        pq;
    pq.em(board[1][1], 1, 1);

    while (!pq.empty()) {
        auto [cost, y, x] = pq.top();
        pq.pop();

        if (result[y][x] != INF)
            continue;

        result[y][x] = cost;

        if (y == n && x == n)
            return;

        rep(i, 0, 3) {
            int ny = y + dy[i], nx = x + dx[i];

            if (isOut(ny, nx) || result[ny][nx] != INF)
                continue;

            pq.em(cost + board[ny][nx], ny, nx);
        }
    }
}

void output() { cout << "Problem " << t++ << ": " << result[n][n] << endl; }

int main() {
    fastio;

    while (cin >> n && n != 0) {
        input();
        solve();
        output();
    }
}