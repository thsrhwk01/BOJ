#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

const long long INF = 0x7f7f7f7f7f7f7f7f;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<vector<long long>> board(n, vector<long long>(n)),
        dp(n, vector<long long>(n));

    for (auto &&row : board) {
        for (auto &&cell : row) {
            cin >> cell;
        }
    }

    auto isOut = [&](int x, int y) {
        return x < 0 or y < 0 or x >= n or y >= n;
    };

    int dx[] = {-1, 0};
    int dy[] = {0, -1};

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (x == 0 and y == 0) {
                continue;
            }

            dp[x][y] = INF;

            for (int dir = 0; dir < 2; dir++) {
                int bx = x + dx[dir], by = y + dy[dir];

                if (isOut(bx, by)) {
                    continue;
                }

                dp[x][y] = min(dp[x][y], dp[bx][by] + (board[bx][by] > board[x][y] ? 0 : board[x][y] - board[bx][by] + 1));
            }
        }
    }

    cout << dp[n - 1][n - 1];

    return 0;
}