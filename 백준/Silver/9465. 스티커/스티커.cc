//
// Created by woo-young Choi on 2022/10/24.
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

vii stickers;
vii results;

int n;

void input() {
    cin >> n;

    stickers.resize(n);

    for (auto &p: stickers) {
        cin >> p.first;
    }

    for (auto &p: stickers) {
        cin >> p.second;
    }
}

void solve() {
    results.resize(n + 2);
    results[0] = {0, 0};
    results[1] = {0, 0};

    for (int i = 0; i < stickers.size(); ++i) {
        results[i + 2].first = max(results[i + 1].second + stickers[i].first,
                                   results[i].second + stickers[i].first);
        results[i + 2].second = max(results[i + 1].first + stickers[i].second,
                                    results[i].first + stickers[i].second);
    }
}

void output() {
    cout << max(results[n + 1].first, results[n + 1].second) << endl;
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
