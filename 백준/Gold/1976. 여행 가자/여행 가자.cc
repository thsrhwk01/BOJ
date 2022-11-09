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

vector<int> vec, checking;
int n, m;
bool ans;

int getParent(int x) {
    return (vec[x] == x ? x : getParent(vec[x]));
}

bool isSameParent(int x, int y) {
    return getParent(x) == getParent(y);
}

void unionParent(int x, int y) {
    x = getParent(x);
    y = getParent(y);

    vec[max(x, y)] = min(x, y);
}

void input() {
    cin >> n >> m;
    vec.resize(n + 1);
    iota(range(vec), 0);
    checking.resize(m);

    bool tmp;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> tmp;
            if (tmp) unionParent(min(i, j), max(i, j));
        }
    }

    for (auto &check: checking) {
        cin >> check;
    }
}

void solve() {
    for (int i = 1; i < m; ++i) {
        if (!isSameParent(checking[i - 1], checking[i])) {
            ans = false;
            return;
        }
    }

    ans = true;
}

void output() {
    cout << (ans ? "YES" : "NO");
}

int main() {
    fastio

    input();
    solve();
    output();
}
