#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, m;
    cin >> n >> m;

    vector<pair<ll, ll>> vec(n);
    for (auto &&[c, w] : vec) {
        cin >> w >> c;
    }

    sort(vec.begin(), vec.end(), [](auto x, auto y) {
        swap(x.second, y.second);
        return x < y;
    });

    ll bCost = -1, wSum = 0, tAns = 0, ans = LONG_MAX;

    for (const auto &[c, w] : vec) {
        if (bCost != c) {
            bCost = c;
            tAns = 0;
        }

        tAns += c;
        wSum += w;

        if (wSum >= m) {
            ans = min(ans, tAns);
        }
    }

    cout << (ans == LONG_MAX ? -1 : ans);

    return 0;
}