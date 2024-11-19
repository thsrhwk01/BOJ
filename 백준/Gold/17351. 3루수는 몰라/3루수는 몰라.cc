#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl '\n'

int dx[] = {0, 1};
int dy[] = {1, 0};

char board[501][501];
int dp[501][501];
vector<pair<int, int>> points[501][501], starts;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];

            if (board[i][j] == 'M') {
                starts.emplace_back(i, j);
            }
        }
    }

    auto isOut = [&](int x, int y) {
        return x < 0 or x >= n or y < 0 or y >= n;
    };

    for (auto [i, j] : starts) {
        queue<pair<string, pair<int, int>>> q;
        q.emplace("M", make_pair(i, j));

        while (!q.empty()) {
            auto [str, p] = q.front();
            auto [x, y] = p;
            q.pop();

            if (str.size() == 4) {
                if (str == "MOLA" and
                    (points[x][y].empty() or
                     points[x][y].back() != make_pair(i, j))) {
                    points[x][y].emplace_back(i, j);
                }

                continue;
            }

            for (int k = 0; k < 2; ++k) {
                int nx = x + dx[k], ny = y + dy[k];

                if (isOut(nx, ny)) {
                    continue;
                }

                q.emplace(str + board[nx][ny], make_pair(nx, ny));
            }
        }
    }

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (!isOut(x - 1, y)) {
                dp[x][y] = max(dp[x][y], dp[x - 1][y]);
            }

            if (!isOut(x, y - 1)) {
                dp[x][y] = max(dp[x][y], dp[x][y - 1]);
            }

            for (auto &[i, j] : points[x][y]) {
                dp[x][y] = max(dp[x][y], dp[i][j] + 1);
            }
        }
    }

    cout << dp[n - 1][n - 1];

    return 0;
}