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

    int n, m;

    cin >> n;

    vi cards(n);
    for (auto &card : cards) cin >> card;

    sort(all(cards));

    cin >> m;

    vi queries(m);
    for (auto &query : queries) cin >> query;

    for (const auto &query : queries) {
        int l = 0, r = n - 1;

        while (l + 1 < r) {
            int mid = (l + r) / 2;

            if (cards[mid] < query) {
                l = mid;
            } else {
                r = mid;
            }
        }

        cout << ((cards[l] == query or cards[r] == query) ? 1 : 0) << ' ';
    }
}