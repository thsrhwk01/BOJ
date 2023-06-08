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

int homeNumber, routerNumber, ans;

vi homeList;

void input() {
    cin >> homeNumber >> routerNumber;

    int coor;
    rep(i, 1, homeNumber) {
        cin >> coor;

        homeList.emb(coor);
    }
}

void solve() {
    sort(all(homeList));

    int low = 1, high = homeList.back() - homeList.front();

    while (low <= high) {
        int setupNumber = 1;
        int mid = (low + high) / 2;

        int now = homeList.front();
        for (const auto &nx : homeList) {
            if (nx - now < mid)
                continue;

            ++setupNumber;
            now = nx;
        }

        if (setupNumber >= routerNumber) {
            ans = mid;
            low = mid + 1;
        } else
            high = mid - 1;
    }
}

void output() { cout << ans; }

int main() {
    fastio;

    input();
    solve();
    output();
}