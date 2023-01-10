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

int g, n;
queue<int> q;
set<int> s;

void input() {
    cin >> g >> n;

    int tmp;
    while(n--) {
        cin >> tmp;
        q.em(tmp);
    }
}

void solve() {
    for (int i = 1; i <= g; ++i) s.em(i);

    while (!q.empty() && !s.empty()) {
        auto mg = q.front();
        q.pop();

        auto enable = s.upper_bound(mg);

        if (enable == s.begin()) return;

        s.erase(prev(enable));
    }
}

void output() {
    cout << g - s.size();
}

int main() {
    fastio

    input();
    solve();
    output();
}