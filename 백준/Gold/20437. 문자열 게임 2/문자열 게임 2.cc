//
// Created by 99woo on 2023-01-06.
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

vector<vector<int>> vec;
int n, ans1, ans2;
const int INF = 123'456'789;

void input() {
    vec.clear();
    vec.resize(26);

    string tmp;
    cin >> tmp >> n;

    for (int i = 0; i < tmp.size(); ++i) {
        vec[tmp[i] - 'a'].emb(i);
    }
}

void solve() {
    ans1 = INF;
    ans2 = -1;

    for (const auto& v: vec) {
        if (v.size() >= n) {
            for (int i = 0; i < v.size() - n + 1; ++i) {
                ans1 = min(ans1, v[i + n - 1] - v[i] + 1);
                ans2 = max(ans2, v[i + n - 1] - v[i] + 1);
            }
        }
    }
}

void output() {
    if (ans1 == INF) cout << -1 << endl;
    else cout << ans1 << ' ' << ans2 << endl;
}

int main() {
    fastio

    int t;
    cin >> t;

    while (t--) {
        input();
        solve();
        output();
    }
}