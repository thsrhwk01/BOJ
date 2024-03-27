#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using tiii = tuple<int, int, int>;
using viii = vector<tiii>;

#define endl '\n'
#define em emplace
#define emb emplace_back
#define all(x) x.begin(), x.end()
#define rep(i, from, to) for (int i = from; i <= to; ++i)
#define fastio                        \
    iostream::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

int main() {
    fastio;

    int n, totalBudget;
    cin >> n;

    vector<ll> budgets(n);

    for (auto &budget : budgets) cin >> budget;

    cin >> totalBudget;

    ll l = 0, r = 1'000'000'001;

    while (l + 1 < r) {
        ll mid = (l + r) / 2;
        ll sum = 0;

        for (const auto &budget : budgets) {
            if (budget <= mid) {
                sum += budget;
            } else {
                sum += mid;
            }
        }

        if (sum > totalBudget) {
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << min(*max_element(all(budgets)), l);
}