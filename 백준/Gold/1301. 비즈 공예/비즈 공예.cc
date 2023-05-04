#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using ll = long long;

#define endl '\n'
#define em emplace
#define emb emplace_back
#define all(x) x.begin(), x.end()
#define fastio                                                                 \
    iostream::sync_with_stdio(false);                                          \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);

int n, total_limit;
ll ans;
vi limits(6);
// 남은거, 앞에 거, 지금 거
ll dp[11][11][11][11][11][6][6];

void input() {
    //auto cin = fstream("input.txt");
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> limits[i];
        total_limit += limits[i];
    }
}

ll dp_calc(int before, int now, int cnt) {
    if (cnt == total_limit)
        return 1;

    auto &x = dp[limits[1]][limits[2]][limits[3]][limits[4]][limits[5]][before]
                [now];

    if (x != -1) {
        return x;
    }
    x = 0;

    for (int i = 1; i <= n; i++)
    {
        if (i == before or i == now or limits[i] == 0) continue;
        --limits[i];
        x += dp_calc(now, i, cnt + 1);
        ++limits[i];
    }

    return x;
}

void solve() {
    memset(dp, -1, sizeof(dp));

    ans = dp_calc(0, 0, 0);
}

void output() { cout << ans; }

int main() {
    fastio;

    input();
    solve();
    output();
}