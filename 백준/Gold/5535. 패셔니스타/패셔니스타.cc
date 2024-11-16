#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int d, n;
    cin >> d >> n;

    vector<int> temps(d);
    for (auto &&temp : temps) {
        cin >> temp;
    }

    vector<tuple<int, int, int>> cInfos(n);
    for (auto &&[a, b, c] : cInfos) {
        cin >> a >> b >> c;
    }

    auto isIn = [](int a, int b, int x) { return x >= a and x <= b; };

    vector<vector<int>> dp(d, vector<int>(n));
    for (int i = 0; i < n; i++) {
        auto [a, b, c] = cInfos[i];
        auto temp = temps[0];

        if (isIn(a, b, temp)) {
            dp[0][i] = 0;
        } else {
            dp[0][i] = -1;
        }
    }

    for (int i = 1; i < d; i++) {
        auto temp = temps[i];

        for (int j = 0; j < n; j++) {
            auto [a, b, c] = cInfos[j];

            if (!isIn(a, b, temp)) {
                dp[i][j] = -1;
                continue;
            }
            int maximum = 0;

            for (int k = 0; k < n; k++) {
                auto [ba, bb, bc] = cInfos[k];
                if (dp[i - 1][k] == -1) {
                    continue;
                }

                int t = max(bc, c) - min(bc, c) + dp[i - 1][k];
                maximum = max(maximum, t);
            } 

            dp[i][j] = maximum;
        }
    }

    cout << *max_element(dp[d - 1].begin(), dp[d - 1].end());

    return 0;
}