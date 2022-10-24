//
// Created by woo-young Choi on 2022/10/23.
//

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define pii pair<int, int>
#define ll long long
#define emb emplace_back
#define fastio iostream::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

vector<pii> sale;
vector<pair<int, ll>> results;

int n, gap;

bool cmp(pii rhs, pii lhs) {
    swap(rhs.second, lhs.second);
    return rhs < lhs;
}

bool is_unique(const pii &rhs, const pii &lhs) {
    return rhs.first == lhs.first;
}

void input() {
    cin >> n >> gap;

    sale.resize(n);
    for (auto &input: sale) cin >> input.first >> input.second;
}

void solve() {
    sort(sale.begin(), sale.end(), cmp);
    sale.resize(unique(sale.begin(), sale.end(), is_unique) - sale.begin());

    results.resize(sale.size());
    results[0] = sale[0];

    int checker = 0;

    int height;
    ll value;

    for (int i = 1; i < sale.size(); ++i) {
        tie(height, value) = sale[i];

        results[i].first = height;
        results[i].second = max(results[i-1].second, value);

        if (height - results[checker].first >= gap) {
            while (height - results[checker + 1].first >= gap) ++checker;

            results[i].second = max(results[i].second, value + results[checker].second);
        }
    }
}

void output() {
    cout << results.rbegin()->second;
}

int main() {
    fastio

    input();
    solve();
    output();
}
