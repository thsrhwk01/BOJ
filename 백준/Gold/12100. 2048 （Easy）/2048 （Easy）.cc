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

array<array<int, 20>, 20> boardOriginal;

int n, ans;

void input() {
    cin >> n;

    rep(i, 0, n - 1) {
        rep(j, 0, n - 1) { cin >> boardOriginal[i][j]; }
    }
}

void backtracking(const array<array<int, 20>, 20> &boardPrev, int step) {
    if (step == 5) {
        rep(i, 0, n - 1) {
            rep(j, 0, n - 1) { ans = max(ans, boardPrev[i][j]); }
        }

        return;
    }

    array<array<int, 20>, 20> board = boardPrev;

    // up
    rep(colIdx, 0, n - 1) {
        queue<int> q;
        int rowIdx = 0;

        rep(i, 0, n - 1) {
            if (board[i][colIdx] > 0) {
                q.em(board[i][colIdx]);
                board[i][colIdx] = 0;
            }
        }

        while (!q.empty()) {
            int a = q.front();
            q.pop();

            if (!q.empty() and a == q.front()) {
                board[rowIdx++][colIdx] = a + a;
                q.pop();
            } else
                board[rowIdx++][colIdx] = a;
        }
    }
    backtracking(board, step + 1);

    board = boardPrev;
    // down
    rep(colIdx, 0, n - 1) {
        queue<int> q;
        int rowIdx = n - 1;

        for (int i = n - 1; i >= 0; --i) {
            if (board[i][colIdx] > 0) {
                q.em(board[i][colIdx]);
                board[i][colIdx] = 0;
            }
        }

        while (!q.empty()) {
            int a = q.front();
            q.pop();

            if (!q.empty() and a == q.front()) {
                board[rowIdx--][colIdx] = a + a;
                q.pop();
            } else
                board[rowIdx--][colIdx] = a;
        }
    }
    backtracking(board, step + 1);

    board = boardPrev;
    // left
    rep(rowIdx, 0, n - 1) {
        queue<int> q;
        int colIdx = 0;

        rep(j, 0, n - 1) {
            if (board[rowIdx][j] > 0) {
                q.em(board[rowIdx][j]);
                board[rowIdx][j] = 0;
            }
        }

        while (!q.empty()) {
            int a = q.front();
            q.pop();

            if (!q.empty() and a == q.front()) {
                board[rowIdx][colIdx++] = a + a;
                q.pop();
            } else
                board[rowIdx][colIdx++] = a;
        }
    }
    backtracking(board, step + 1);

    board = boardPrev;
    // right
    rep(rowIdx, 0, n - 1) {
        queue<int> q;
        int colIdx = n - 1;

        for (int j = n - 1; j >= 0; --j) {
            if (board[rowIdx][j] > 0) {
                q.em(board[rowIdx][j]);
                board[rowIdx][j] = 0;
            }
        }

        while (!q.empty()) {
            int a = q.front();
            q.pop();

            if (!q.empty() and a == q.front()) {
                board[rowIdx][colIdx--] = a + a;
                q.pop();
            } else
                board[rowIdx][colIdx--] = a;
        }
    }
    backtracking(board, step + 1);
}

void solve() { backtracking(boardOriginal, 0); }

void output() { cout << ans; }

int main() {
    fastio;

    input();
    solve();
    output();
}