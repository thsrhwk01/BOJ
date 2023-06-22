//
// Created by woo-young Choi on 2022/11/08.
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
#define fastio                                                                 \
    iostream::sync_with_stdio(false);                                          \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);

vector<double> vec;
double result;
int n;

void input() {
    cin >> n;
    vec.resize(n);

    for (auto &x : vec)
        cin >> x;
}

void solve() {
    double average = accumulate(range(vec), 0.0) / n;
    auto cnt = count_if(range(vec), [&](double &i) { return i > average; });
    result = round(double(cnt) / n * 100000) / 1000;
}

void output() {
    cout.precision(3);
    cout << fixed << result << '%' << endl;
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
