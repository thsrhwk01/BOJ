#include <iostream>

using namespace std;

#define ednl '\n'

void solve() {
    int x1, y1, x2, y2, r1, r2;

    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    if (x1 == x2 and y1 == y2) {
        if (r1 == r2) {
            cout << -1 << endl;

            return;
        } else {
            cout << 0 << endl;

            return;
        }
    }

    int pDist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2),
        rDist1 = (r1 + r2) * (r1 + r2), rDist2 = (r1 - r2) * (r1 - r2);

    if (pDist == rDist1 or pDist == rDist2) {
        cout << 1 << endl;

        return;
    }

    if (pDist < rDist1 and pDist > rDist2) {
        cout << 2 << endl;

        return;
    }

    cout << 0 << endl;

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