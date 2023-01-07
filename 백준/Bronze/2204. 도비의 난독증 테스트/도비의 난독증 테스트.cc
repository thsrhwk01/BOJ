//
// Created by woo-young Choi on 2023/01/07.
//

#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<pii>;
using ll = long long;

#define endl '\n'
#define em emplace
#define emb emplace_back
#define all(x) x.begin(), x.end()
#define fastio iostream::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

void makelower(char &c) {
    if (c < 'a') c += 32;
}

bool cmp(string rhs, string lhs) {
    for_each(all(rhs), makelower);
    for_each(all(lhs), makelower);

    return rhs < lhs;
}

void solve(int t) {
    vector<string> strs(t);

    for (auto &str: strs) cin >> str;

    sort(all(strs), cmp);

    cout << strs.front() << endl;
}

int main() {
    fastio

    int t;

    while (cin >> t && t != 0) {
        solve(t);
    }
}
