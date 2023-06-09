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
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

vvi cctvDir[6] = {{{}},
                  {{0}, {1}, {2}, {3}},
                  {{0, 1}, {2, 3}},
                  {{0, 2}, {2, 1}, {1, 3}, {3, 0}},
                  {{0, 1, 2}, {0, 1, 3}, {0, 2, 3}, {1, 2, 3}},
                  {{0, 1, 2, 3}}};

// cctv, y, x
vector<tuple<int, int, int>> cctvList;

vvi boardOriginal;

int n, m, ans = 65, zeroCntOrig = 0;

void input() {
    cin >> n >> m;
    boardOriginal.resize(n);

    rep(i, 0, n - 1) {
        boardOriginal[i].resize(m);

        rep(j, 0, m - 1) {
            cin >> boardOriginal[i][j];

            if (boardOriginal[i][j] == 0)
                ++zeroCntOrig;
            else if (boardOriginal[i][j] != 6)
                cctvList.emb(boardOriginal[i][j], i, j);
        }
    }
}

inline bool isOut(int y, int x) { return y < 0 || y >= n || x < 0 || x >= m; }

void backtracking(int step, int zeroCnt, const vvi &board) {
    if (step == cctvList.size()) {
        ans = min(ans, zeroCnt);
        return;
    }

    const auto [cctv, y, x] = cctvList[step];

    for (const auto &dirSet : cctvDir[cctv]) {
        vvi boardTmp = board;
        int tCnt = zeroCnt;

        for (const auto &dir : dirSet) {
            int ty = y, tx = x;

            while (!isOut(ty, tx) && boardTmp[ty][tx] != 6) {
                if (boardTmp[ty][tx] == 0) {
                    tCnt--;
                    boardTmp[ty][tx] = 7;
                }
                ty += dy[dir];
                tx += dx[dir];
            }
        }

        backtracking(step + 1, tCnt, boardTmp);
    }
}

void solve() { backtracking(0, zeroCntOrig, boardOriginal); }

void output() { cout << ans; }

int main() {
    fastio;

    input();
    solve();
    output();
}