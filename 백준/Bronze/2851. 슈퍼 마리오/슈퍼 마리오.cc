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
#define fastio iostream::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

vector<int> sums;
int first, second;

void input() {
    sums.emb(0);
    int tmp;
    while (cin >> tmp && sums.back() < 100) {
        sums.emb(sums.back() + tmp);
    }
}

void solve() {
    first = *sums.rbegin();
    second = *next(sums.rbegin());
}

void output() {
    if (second == 0 || first - 100 <= 100 - second) cout << first;
    else cout << second;
}

int main() {
    fastio

    input();
    solve();
    output();
}
