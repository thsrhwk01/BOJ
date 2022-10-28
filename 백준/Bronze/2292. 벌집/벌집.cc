//
// Created by woo-young Choi on 2022/08/13.
//

#include <iostream>

using namespace std;

int main() {
    double n; cin >> n;

    double line = 0;
    double cnt = 0;

    if (n == 1) { cout << 1; return 0; }

    --n;
    while (n > 0) {
        n -= line;
        ++cnt;
        line += 6;
    }

    cout << cnt;
}