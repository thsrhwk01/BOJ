//
// Created by woo-young Choi on 2022/11/09.
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
vector<int> vec(10001);

void input() {
    cin >> n;
    while (cin >> n) ++vec[n];
}

void output() {
    for (int i = 1; i <= 10000; ++i)
        for (int j = 0; j < vec[i]; ++j)
            cout << i << endl;
}

int main() {
    fastio

    input();
    output();
}
