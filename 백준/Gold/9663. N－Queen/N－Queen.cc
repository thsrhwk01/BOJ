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

int n, ans = 0;

vector<int> vec;

void sum_nqueen(int row) {
    if (row == n) {
        ans += 1;
        return;
    }

    for (int i = 0; i < n; ++i) {
        vec[row] = i;

        [&] {
            for (int j = 0; j < row; ++j) {
                if (vec[j] == i ||
                    abs(i - vec[j]) == abs(row - j)) return;
            }

            sum_nqueen(row + 1);
        } ();
    }

    vec[row] = -100;
}

void input() {
    cin >> n;

    vec.resize(n);
    fill(range(vec), -100);
}

void solve() {
    sum_nqueen(0);
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