//
// Created by woo-young Choi on 2022/09/22.
//

#include <bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

int x, y;
string ans;
map<pii, string> mp;

string add_str(string l, string r) {
    string res;
    auto lit = l.rbegin();
    auto rit = r.rbegin();

    int ten = 0, tmp;
    while ((lit != l.rend()) || (rit != r.rend())) {
        tmp = 0;

        if (lit != l.rend()) tmp += (*lit++ - '0');
        if (rit != r.rend()) tmp += (*rit++ - '0');

        tmp += ten;
        ten = tmp / 10;

        res.insert(res.begin(), char(tmp % 10 + '0'));
    }

    if (ten == 1) res.insert(res.begin(), char(ten + '0'));

    return res;
}



string combination(int n, int r) {
    if (r == 0 || r == n) return "1";
    if (r == 1 || n - r == 1) return to_string(n);

    pii key = {n, r};
    if (mp.find(key) != mp.end()) return mp[key];

    auto res = add_str(combination(n - 1, r), combination(n - 1, r - 1));
    pii rkey = {n, n - r};

    mp[key] = res;
    mp[rkey] = res;

    return res;
}

void input() {
    cin >> x >> y;
}

void solve() {
    ans = combination(x, y);
}

void output() {
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    solve();
    output();
}
