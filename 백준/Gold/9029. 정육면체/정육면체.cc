#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

#define endl '\n'

long long dp[205][205][205];

void dpCalc() {
    for (int i = 1; i < 201; ++i) {
        for (int j = 1; j < 201; ++j) {
            for (int k = 1; k < 201; ++k) {
                auto &now = dp[i][j][k];

                if (i == j and j == k) {
                    now = 1;

                    continue;
                } else {
                    now = 0x7f7f7f7f7f7f7f7f;
                }

                for (int h = 1; h < i; ++h) {
                    now = min(now, dp[i - h][j][k] + dp[h][j][k]);
                }

                for (int h = 1; h < j; ++h) {
                    now = min(now, dp[i][j - h][k] + dp[i][h][k]);
                }

                for (int h = 1; h < k; ++h) {
                    now = min(now, dp[i][j][k - h] + dp[i][j][h]);
                }
            }
        }
    }
}

void solve() {
    int w, l, h;
    cin >> w >> l >> h;

    cout << dp[w][l][h] << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    dpCalc();

    while (t--) {
        solve();
    }

    return 0;
}