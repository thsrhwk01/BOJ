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

int board[10][10];

vii blankList;

bool row[9][10], col[9][10], square[3][3][10];

void input() {
    int num;
    rep(i, 0, 8) {
        rep(j, 0, 8) {
            cin >> num;

            board[i][j] = num;

            if (num == 0)
                blankList.emb(i, j);

            row[i][num] = true;
            col[j][num] = true;
            square[i / 3][j / 3][num] = true;
        }
    }
}

bool backtracking(int step) {
    if (step == blankList.size())
        return true;

    auto [y, x] = blankList[step];

    rep(i, 1, 9) {
        if (row[y][i] || col[x][i] || square[y / 3][x / 3][i])
            continue;

        row[y][i] = true;
        col[x][i] = true;
        square[y / 3][x / 3][i] = true;

        board[y][x] = i;

        bool childReturn = backtracking(step + 1);

        if (childReturn)
            return true;

        row[y][i] = false;
        col[x][i] = false;
        square[y / 3][x / 3][i] = false;

        board[y][x] = 0;
    }

    return false;
}

void solve() { backtracking(0); }

void output() {
    cout << endl;
    rep(i, 0, 8) {
        rep(j, 0, 8) {
            cout << board[i][j] << ' ';
        }

        cout << endl;
    }
}

int main() {
    fastio;

    input();
    solve();
    output();
}