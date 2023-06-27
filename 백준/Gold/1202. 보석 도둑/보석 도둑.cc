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

int n, m;

ll ans;

// {weight, value}
vii jewels;
vi bags;

void input() {
    cin >> n >> m;

    jewels.resize(n);
    for (auto &p : jewels)
        cin >> p.first >> p.second;

    bags.resize(m);
    for (auto &b : bags)
        cin >> b;
}

void solve() {
    sort(all(jewels));
    sort(all(bags));

    int jewelIdx = 0;

    priority_queue<int> pq;

    for (const auto &b : bags) {
        while (jewelIdx < n and jewels[jewelIdx].first <= b)
            pq.em(jewels[jewelIdx++].second);

        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }
}

void output() { cout << ans; }

int main() {
    fastio;

    input();
    solve();
    output();
}