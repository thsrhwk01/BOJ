//
// Created by woo-young Choi on 2022/10/25.
//

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define pii pair<int, int>
#define vii vector<pii>
#define ll long long

#define em emplace
#define emb emplace_back
#define range(x) x.begin(), x.end()
#define fastio iostream::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int n;
deque<int> prefix;

void input() {
    prefix.resize(n);

    for (auto &input: prefix) cin >> input;
    prefix.push_front(0);
}

void output() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < prefix[i] - prefix[i - 1]; ++j) {
            cout << i << ' ';
        }
    }
    cout << endl;
}

int main() {
    fastio

    while (cin >> n && n != 0) {
        input();
        output();
    }
}