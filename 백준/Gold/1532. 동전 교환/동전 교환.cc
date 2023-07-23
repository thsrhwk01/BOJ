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

int goldNeed, goldNow, silverNeed, silverNow, breonzeNeed, bronzeNow, ans;

void input() {
    cin >> goldNow >> silverNow >> bronzeNow >> goldNeed >> silverNeed >>
        breonzeNeed;
}

void solve() {
    while (true) {
        if (goldNow >= goldNeed && silverNow >= silverNeed &&
            bronzeNow >= breonzeNeed)
            return;

        if (goldNow < goldNeed && silverNow < silverNeed &&
            bronzeNow < breonzeNeed) {
            ans = -1;
            return;
        }

        ++ans;

        if (goldNow < goldNeed) {
            if (silverNow >= 11) {
                silverNow -= 11;
                goldNow += 1;
            } else if (bronzeNow >= 11) {
                bronzeNow -= 11;
                silverNow += 1;
            } else {
                ans = -1;
                return;
            }
        } else if (silverNow < silverNeed) {
            if (goldNow > goldNeed) {
                goldNow -= 1;
                silverNow += 9;
            } else if (bronzeNow >= 11) {
                bronzeNow -= 11;
                silverNow += 1;
            } else {
                ans = -1;
                return;
            }
        } else {
            if (silverNow >= 1) {
                silverNow -= 1;
                bronzeNow += 9;
            } else if (goldNow >= 1) {
                goldNow -= 1;
                silverNow += 9;
            } else {
                ans = -1;
                return;
            }
        }

        // cout << goldNow << ' ' << silverNow << ' ' << bronzeNow << endl;
    }
}

void output() { cout << ans; }

int main() {
    fastio;

    input();
    solve();
    output();
}