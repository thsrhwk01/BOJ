#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <numeric>
#include <tuple>
#include <vector>

using namespace std;

using ll = long long;

#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<tuple<ll, ll, ll>> schedules(n);

    for (auto &&schedule : schedules) {
        auto &[to, from, num] = schedule;

        cin >> from >> to >> num;
    }

    sort(schedules.begin(), schedules.end());

    vector<ll> dp(n);
    dp[0] = get<2>(schedules[0]);
    ll ans = dp[0];

    for (int i = 1; i < n; i++) {
        auto [to, from, num] = schedules[i];

        auto idx =
            lower_bound(schedules.begin(), schedules.end(), from,
                        [](const auto &x, auto y) { return get<0>(x) <= y; }) -
            schedules.begin() - 1;

        dp[i] = max(dp[i - 1], (idx >= 0 ? dp[idx] + num : num));

        ans = max(ans, dp[i]);
    }

    cout << ans;

    return 0;
}