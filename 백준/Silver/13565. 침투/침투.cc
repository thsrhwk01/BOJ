//
// Created by woo-young Choi on 2022/11/03.
//

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define pii pair<int, int>
#define vii vector<pii>
#define ll long long

#define em emplace
#define emb emplace_back
#define range(x) x.begin(), x.end()
#define fastio iostream::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int n, m;
queue<pii > q;
vector<vector<int>> board;
bool result;

int rangex[4] = {-1, 0, 1, 0};
int rangey[4] = {0, -1, 0, 1};

void input() {
    cin >> m >> n;
    board.resize(m);

    for (auto &row: board) {
        row.resize(n);

        char x;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            row[i] = x - '0';
        }
    }
}

bool solve() {
    for (int i = 0; i < n; ++i) {
        if (board[0][i] == 0) {
            q.em(0, i);
            board[0][i] = 1;
        }
    }

    int x, y, xx, yy;
    while (!q.empty()) {
        tie(x, y) = q.front();

        q.pop();

        for (int i = 0; i < 4; ++i) {
            xx = x + rangex[i];
            yy = y + rangey[i];

            if (xx < 0 || xx >= m) continue;
            if (yy < 0 || yy >= n) continue;

            if (board[xx][yy] == 0) {
                if (xx == m - 1) {
                    return true;
                }

                q.em(xx, yy);
                board[xx][yy] = 1;
            }
        }
    }

    return false;
}

void output() {
    cout << (result ? "YES" : "NO");
}

int main() {
    fastio

    input();
    result = solve();
    output();
}
