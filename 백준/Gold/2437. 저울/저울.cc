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

int n;
ll ans;
vi weights;

void input() {
    cin >> n;

    weights.resize(n);

    for (auto &weight : weights)
        cin >> weight;
}

void solve() {
    sort(all(weights));

    for (const auto &weight: weights) {
        if (ans + 1 < weight) return;

        ans += weight;
    }
}

void output() {
    cout << ans + 1;
}

int main() {
    fastio;

    input();
    solve();
    output();
}