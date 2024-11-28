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
        int l = i - 1, r = i + 1, now = vec[i] * 2;

        while (l >= 0 and r < n) {
            auto sum = vec[l] + vec[r];

            if (sum == now) {
                ++ans;
                --l;
                ++r;
            } else if (sum > now) {
                --l;
            } else {
                ++r;
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