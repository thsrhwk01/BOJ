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

int n, m, ans = 0x3f3f3f3f;

vi combi;

vii chickens, houses;

void input() {
    cin >> n >> m;

    int type;
    rep(i, 1, n) {
        rep(j, 1, n) {
            cin >> type;
            switch (type) {
            case 1:
                houses.emb(i, j);
                break;
            case 2:
                chickens.emb(i, j);
                break;
            }
        }
    }
}

void calculate() {
    int sum = 0;

    for (auto house : houses) {
        int tmp = 0x3f3f3f3f;
        auto [y, x] = house;

        for (int i : combi)
            tmp = min(tmp,
                      abs(chickens[i].first - y) + abs(chickens[i].second - x));

        sum += tmp;
    }

    ans = min(ans, sum);
}

void backtracking(int idx) {
    if (idx != -1)
        combi.emb(idx);

    if (combi.size() == m)
        calculate();
    else
        rep(i, idx + 1, chickens.size() - 1) backtracking(i);

    if (idx != -1)
        combi.pop_back();
}

void solve() { backtracking(-1); }

void output() { cout << ans; }

int main() {
    fastio;

    input();
    solve();
    output();
}