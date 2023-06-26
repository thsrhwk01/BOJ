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

int n, len, board[100][100];

bool rowCheck[100], colCheck[100];

void input() {
    cin >> n >> len;

    rep(i, 0, n - 1) {
        rep(j, 0, n - 1) { cin >> board[i][j]; }
    }
}

void rowDFS(const int rowNum, int idx, int cnt) {
    if (idx == n - 1 and cnt >= 0) {
        rowCheck[rowNum] = true;
        return;
    }

    int nowValue = board[rowNum][idx], nextValue = board[rowNum][idx + 1];

    switch (nextValue - nowValue) {
    case 0:
        rowDFS(rowNum, idx + 1, cnt + 1);
        break;
    case 1:
        // upstair
        if (cnt < len)
            return;
        rowDFS(rowNum, idx + 1, 1);
        break;
    case -1:
        // downstair
        if (cnt < 0)
            return;
        rowDFS(rowNum, idx + 1, -len + 1);
        break;
    }
}

void colDFS(const int colNum, int idx, int cnt) {
    if (idx == n - 1 and cnt >= 0) {
        colCheck[colNum] = true;
        return;
    }

    int nowValue = board[idx][colNum], nextValue = board[idx + 1][colNum];

    switch (nextValue - nowValue) {
    case 0:
        colDFS(colNum, idx + 1, cnt + 1);
        break;
    case 1:
        if (cnt < len)
            return;
        colDFS(colNum, idx + 1, 1);
        break;
    case -1:
        if (cnt < 0)
            return;
        colDFS(colNum, idx + 1, -len + 1);
        break;
    }
}

void solve() {
    rep(i, 0, n - 1) {
        rowDFS(i, 0, 1);
        colDFS(i, 0, 1);
    }
}

void output() {
    int cnt = 0;
    rep(i, 0, n - 1) {
        cnt += rowCheck[i];
        cnt += colCheck[i];
    }

    cout << cnt;
}

int main() {
    fastio;

    input();
    solve();
    output();
}