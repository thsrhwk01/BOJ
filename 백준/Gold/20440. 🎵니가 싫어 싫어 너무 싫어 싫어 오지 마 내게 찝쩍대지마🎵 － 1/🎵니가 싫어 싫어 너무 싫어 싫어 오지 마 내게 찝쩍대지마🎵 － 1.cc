#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

#define endl '\n'
#define em emplace
#define emb emplace_back
#define all(x) x.begin(), x.end()
#define rep(i, from, to) for (int i = from; i <= to; ++i)
#define fastio                                                                 \
    iostream::sync_with_stdio(false);                                          \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);

vii logs;

int mosNumber, ans;
pii ansDuration;

void input() {
    cin >> mosNumber;

    rep(i, 1, mosNumber) {
        int in, out;
        cin >> in >> out;

        logs.emb(in, +1);
        logs.emb(out, -1);
    }
}

void solve() {
    logs.emb(2'100'000'001, -1);
    sort(all(logs));

    int nowCnt = 0;
    ansDuration.first = 0;
    bool isMax = true;

    vii compressed;

    int idx = 0, value = 0;

    for (auto &log : logs) {
        auto [a, b] = log;

        if (idx != a) {
            compressed.emb(idx, value);
            idx = a;
            value = 0;
        }

        value += b;
    }

    for (auto &log : compressed) {
        tie(idx, value) = log;

        if (value < 0 && isMax) {
            ansDuration.second = idx;
            isMax = false;
        } else if (value > 0 && nowCnt + value > ans) {
            ansDuration.first = idx;
            ans = nowCnt + value;
            isMax = true;
        }

        nowCnt += value;
    }
}

void output() {
    cout << ans << endl << ansDuration.first << ' ' << ansDuration.second;
}

int main() {
    fastio;

    input();
    solve();
    output();
}