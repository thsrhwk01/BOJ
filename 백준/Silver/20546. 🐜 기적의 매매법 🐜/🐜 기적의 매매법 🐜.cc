//
// Created by woo-young Choi on 2022/11/04.
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
#define fastio iostream::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int xmoney, ymoney, xstock = 0, ystock = 0;

bool is_up = true;
int cnt = 0;

vector<int> chart(14);

void input() {
    cin >> xmoney;
    ymoney = xmoney;

    for (auto &i: chart) cin >> i;
}

void solve() {
    if (chart[0] <= xmoney) {
        xstock += xmoney / chart[0];
        xmoney %= chart[0];
    }


    for (int i = 1; i < 14; ++i) {
        if (chart[i] != chart[i - 1]) {
            if (is_up != (chart[i] > chart[i - 1])) {
                is_up = !is_up;
                cnt = 1;
            } else if (++cnt >= 3) {
                if (is_up) {
                    ymoney += ystock * chart[i];
                    ystock = 0;
                } else {
                    ystock += ymoney / chart[i];
                    ymoney %= chart[i];
                }
            }

            if (chart[i] <= xmoney) {
                xstock += xmoney / chart[i];
                xmoney %= chart[i];
            }
        }
    }

    xmoney += xstock * chart[13];
    ymoney += ystock * chart[13];
}

void output() {
    if (xmoney == ymoney) cout << "SAMESAME";
    else cout << (xmoney > ymoney ? "BNP" : "TIMING");
}

int main() {
    fastio

    input();
    solve();
    output();
}
