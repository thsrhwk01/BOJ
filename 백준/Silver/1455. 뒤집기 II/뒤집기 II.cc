#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

#define endl '\n'

vector<vector<int>> board;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    board.resize(n);
    for_each(board.begin(), board.end(), [&](auto &row) { row.resize(m); });

    for (auto &&row : board) {
        for (auto &&i : row) {
            char tmp;
            cin >> tmp;

            i = tmp - '0';
        }
    }

    int ans = 0;

    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            if (board[i][j] == 0) {
                continue;
            }

            ans++;

            for (int k = 0; k <= i; k++) {
                for (int l = 0; l <= j; l++) {
                    board[k][l] = (board[k][l] == 0 ? 1 : 0);
                }
            }
        }
    }

    cout << ans;

    return 0;
}