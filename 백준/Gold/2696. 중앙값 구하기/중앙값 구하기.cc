//
// Created by 99woo on 2023-01-23.
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

void solve() {
    multiset<int> s;
    queue<int> q;

    int n, tmp;

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> tmp;
        s.em(tmp);

        if (i & 1) {
            auto it = s.begin();
            advance(it, i / 2);
            q.em(*it);
        }
    }

    cout << q.size() << endl;
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < min(10, sz); ++i) {
            cout << q.front() << ' ';
            q.pop();
        }

        cout << endl;
    }
}

int main() {
    fastio

    int t;
    cin >> t;

    while (t--) solve();
}