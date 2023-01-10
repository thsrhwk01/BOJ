//
// Created by 99woo on 2023-01-10.
//

#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;
using vii = vector<pii>;
using ll = long long;

#define endl '\n'
#define em emplace
#define emb emplace_back
#define all(x) x.begin(), x.end()
#define fastio iostream::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

vector<int> v;
int g, n, ans = 0;
queue<int> q;

void input() {
    cin >> g >> n;

    int tmp;
    while (n--) {
        cin >> tmp;
        q.em(tmp);
    }
}

int union_find(int i) {
    if (v[i] == i) return i;

    return v[i] = union_find(v[i]);
}

void solve() {
    v.resize(g + 1);
    iota(all(v), 0);

    while (!q.empty()) {
        int plane = q.front();
        q.pop();

        plane = union_find(plane);

        if (plane == 0) return;

        v[union_find(plane)] = union_find(plane - 1);
        ++ans;
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