//
// Created by 99woo on 2023-01-11.
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

vector<int> increasing, decreasing, numbers;
int n, ans = 0;

void input() {
    cin >> n;
    numbers.resize(n + 2);

    for (int i = 1; i <= n; ++i) cin >> numbers[i];
}

void solve() {
    increasing.resize(n + 2);
    decreasing.resize(n + 2);

    for (int i = 1; i <= n; ++i)
        for (int j = i - 1; j >= 0; --j)
            if (numbers[i] > numbers[j])
                increasing[i] = max(increasing[i], increasing[j] + 1);

    for (int i = n; i > 0; --i)
        for (int j = i + 1; j <= n + 1; ++j)
            if (numbers[i] > numbers[j])
                decreasing[i] = max(decreasing[i], decreasing[j] + 1);


    for (int i = 1; i <= n; ++i)
        ans = max(ans, increasing[i] + decreasing[i]);
}

void output() {
    cout << ans - 1;
}

int main() {
    fastio

    input();
    solve();
    output();
}