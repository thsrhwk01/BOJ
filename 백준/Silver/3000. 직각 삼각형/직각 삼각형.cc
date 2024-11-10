#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

#define endl '\n'

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> vec(n);
    map<int, int> x, y;

    for (auto &&i : vec) {
        cin >> i.first >> i.second;

        x[i.first]++;
        y[i.second]++;
    }

    long long ans = 0;

    for (const auto &[i, j] : vec) {
        ll a = x[i] - 1;
        ll b = y[j] - 1;

        ans += a * b;
    }

    cout << ans;

    return 0;
}