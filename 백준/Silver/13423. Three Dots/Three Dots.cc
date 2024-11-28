#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

void solve() {
    int n;
    cin >> n;

    vector<int> vec(n);

    for (auto &&x : vec) {
        cin >> x;
    }

    sort(vec.begin(), vec.end());

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int x = vec[i];
        for (int j = i + 1; j < n; j++) {
            int y = vec[j];

            if ((x + y) & 1) {
                continue;
            }

            int z = (x + y) / 2;

            auto it = lower_bound(vec.begin(), vec.end(), z);

            if (it != vec.end() and *it == z) {
                ++ans;
            }
        }
    }

    cout << ans << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}