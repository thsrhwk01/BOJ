//
// Created by woo-young Choi on 2022/08/13.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    int v[n];

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    sort(v, v+n);

    for (auto x : v) cout << x << '\n';
}