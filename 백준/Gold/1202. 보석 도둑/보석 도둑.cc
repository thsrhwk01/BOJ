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

// {value, weight}
priority_queue<pii> pq;
multiset<int> bags;

ll ans;

void input() {
    int n, m;
    cin >> n >> m;

    int weight, value;
    while (n--) {
        cin >> weight >> value;

        pq.em(value, weight);
    }

    bags.em(-1);
    int limit;
    while (m--) {
        cin >> limit;

        bags.em(limit);
    }
}

void solve() {
    while (!pq.empty()) {
        auto [value, weight] = pq.top();
        pq.pop();

        auto it = bags.lower_bound(weight);

        if (it == bags.end())
            continue;
        bags.erase(it);

        ans += value;
    }
}

void output() { cout << ans; }

int main() {
    fastio;

    input();
    solve();
    output();
}
