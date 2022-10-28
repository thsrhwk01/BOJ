//
// Created by woo-young Choi on 2022/08/13.
//

#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    int tmp = n;

    int jari = 0;
    while (true) {
        tmp /= 10;
        ++jari;
        if (tmp == 0) break;
    }

    for (int i = n - jari * 9; i < n; ++i) {
        if (i < 1) continue;

        int now = i;
        int sum = now;
        while (now != 0) {
            sum += now % 10;
            now /= 10;
        }
        if (sum == n) { cout << i; return 0; }
    }

    cout << 0;
}