//
// Created by woo-young Choi on 2022/08/13.
//

#include <iostream>

using namespace std;

int gcd(const int& x, const int& y) {
    int tmp = x % y;
    if (tmp == 0) return y;
    return gcd(y, tmp);
}

int main () {
    int n, m; cin >> n >> m;

    if (n<m) swap(n, m);

    int max = gcd(n, m);

    cout << max << '\n' << n * m / max;
}