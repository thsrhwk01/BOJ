#include <climits>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

#define endl '\n'

int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        ll l = 0, r = INT_MAX;

        // S_3k = (3k^2 + k) / 2
        while (l + 1 < r) {
            ll mid = (l + r) / 2;
            ll mint = (mid * mid * 3 + mid) / 2;

            if (mint < n)
                l = mid;
            else
                r = mid;
        }

        ll line = l * 3 + 1;
        ll num = line * (line - 1) / 2;

        n -= (l * l * 3 + l) / 2;

        if (n <= r) {
            cout << num + n * 3 - 2 << endl;

            continue;
        }
        n -= r;
        num += line++;

        if (n <= r - 1) {
            cout << num + n * 3 << endl;

            continue;
        }
        n -= r - 1;
        num += line++;

        cout << num + n * 3 - 1 << endl;
    }
}