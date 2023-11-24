#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
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

int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    priority_queue<ll> powers;

    rep(i, 1, n) {
        ll a;
        cin >> a;

        powers.em(a);
    }

    auto cmp = [](pll l, pll r) {
        swap(l.second, r.second);
        return l > r;
    };

    priority_queue<pll, vector<pll>, decltype(cmp)> limits;
    rep(i, 1, m) {
        ll a, b;
        cin >> a >> b;

        limits.em(a, b);
    }

    ll lastDay = 0, currentQuality = 0;

    while (!limits.empty()) {
        auto [day, requirement] = limits.top();
        limits.pop();
        lastDay = day;

        while (currentQuality < requirement) {
            if (powers.empty()) {
                cout << -1;
                return 0;
            }

            auto power = powers.top();
            powers.pop();

            currentQuality += (power + day);
        }
    }

    while (!powers.empty()) {
        auto power = powers.top();
        powers.pop();

        currentQuality += (power + lastDay);
    }

    cout << currentQuality;
}