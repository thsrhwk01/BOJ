//
// Created by woo-young Choi on 2022/08/13.
//

#include <iostream>

using namespace std;

int main() {
    int n, cnt = 0; cin >> n;

    while (n--) {
        int x; cin >> x;

        if (x == 1) continue;

        bool is_prime = true;
        for (int i = 2; i * i <= x; ++i) {
            if (x % i == 0) { is_prime = false; break; }
        }

        if (is_prime) ++cnt;
    }

    cout << cnt;
}