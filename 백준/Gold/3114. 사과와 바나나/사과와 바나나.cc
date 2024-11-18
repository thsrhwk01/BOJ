#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'
#define MN 1'505

int bs[MN][MN], as[MN][MN], dp[MN][MN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int r, c;
    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            as[i][j + 1] = as[i][j];
            bs[i + 1][j] = bs[i][j];

            char a;
            int b;
            cin >> a >> b;

            if (a == 'A') {
                as[i][j + 1] += b;
            } else {
                bs[i + 1][j] += b;
            }
        }
    }

    for (int i = 1; i < r; i++) {
        for (int j = 1; j < c; j++) {
            // from left
            int x = dp[i][j - 1] + bs[i][j];
            // from left-up
            int y = dp[i - 1][j - 1] + as[i][j] + bs[i][j];
            // from up
            int z = dp[i - 1][j] + as[i][j];

            dp[i][j] = max(x, max(y, z));
        }
    }

    cout << dp[r - 1][c - 1];

    return 0;
}