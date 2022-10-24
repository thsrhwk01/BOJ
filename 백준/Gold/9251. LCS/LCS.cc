//
// Created by woo-young Choi on 2022/10/22.
//

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define pii pair<int, int>
#define fastio iostream::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

string str1, str2;
vector<vector<int>> cache;

int ans = 0;

void input() {
    cin >> str1 >> str2;
}

void solve() {
    cache.resize(str2.size() + 1);
    cache[0].resize(str1.size() + 1);

    for (int i = 0; i < str2.size(); ++i) {
        cache[i + 1].resize(str1.size() + 1);

        for (int j = 0; j < str1.size(); ++j) {
            if (str2[i] == str1[j]) cache[i + 1][j + 1] = cache[i][j] + 1;
            else cache[i + 1][j + 1] = max(cache[i][j + 1], cache[i + 1][j]);

            ans = max(ans, cache[i+1][j+1]);
        }
    }
}

void output() {
    cout << ans;
}

int main() {
    fastio

    input();
    solve();
    output();
}
