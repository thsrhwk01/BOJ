#include <iostream>
#include <algorithm>

using namespace std;

#define endl '\n'

int dp[201][201][201];

int dpCalc(int a, int b, int c) {
    if (a > b) {
        swap(a, b);
    }

    if (b > c) {
        swap(b, c);
    }

    if (a > b) {
        swap(a, b);
    }

    auto &ret = dp[a][b][c];

    if (ret > 0) return ret;
    if (a == b and b == c) return ret = 1;

    ret = 0x7f7f7f7f;

    for (int i = 1; i <= a / 2; ++i) {
        ret = min(ret, dpCalc(a - i, b, c) + dpCalc(i, b, c));
    }

    for (int i = 1; i <= b / 2; ++i) {
        ret = min(ret, dpCalc(a, b - i, c) + dpCalc(a, i, c));
    }

    for (int i = 1; i <= c / 2; ++i) {
        ret = min(ret, dpCalc(a, b, c - i) + dpCalc(a, b, i));
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int x, y, z;
        cin >> x >> y >> z;

        cout << dpCalc(x, y, z) << endl;
    }

    return 0;
}