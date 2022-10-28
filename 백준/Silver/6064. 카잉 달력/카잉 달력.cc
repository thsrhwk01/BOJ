#include <iostream>

using namespace std;

int euclidian(int x, int y) {
    return y ? euclidian(y , x % y) : x;
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;

    while (t--) {
        int m, n, x, y; cin >> m >> n >> x >> y;
        int maximum = m * n / euclidian(max(m, n), min(m, n));

        if (x == m && y == n) { cout << maximum << '\n'; continue; }
        if (x == m) x = 0; if (y == n) y = 0;

        bool possible = false;
        if (m > n) {
            for (int i = 0; (i * m + x) < maximum; ++i) {
                int asdf = (i * m + x);
                if (asdf % n == y) {
                    cout << asdf << '\n';
                    possible = true;
                    break;
                }
            }
        }
        else {
            for (int i = 0; (i * n + y) < maximum; ++i) {
                int asdf = (i * n + y);
                if (asdf % m == x) {
                    cout << asdf << '\n';
                    possible = true;
                    break;
                }
            }
        }

        if (!possible) cout << -1 << '\n';
    }
}