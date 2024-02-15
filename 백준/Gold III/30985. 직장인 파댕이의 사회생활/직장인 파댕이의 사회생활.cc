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
#define fastio                        \
    iostream::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

int main() {
    fastio;

    ll n, m, k, ans = 0x7f7f7f7f7f7f7f7f;

    cin >> n >> m >> k;
    vector<pair<ll, ll>> edges[n + 5];

    rep(i, 1, m) {
        int from, to, value;

        cin >> from >> to >> value;

        edges[from].emb(to, value);
        edges[to].emb(from, value);
    }

    vector<ll> elevators(n + 5);
    rep(i, 1, n) { cin >> elevators[i]; }

    vector<ll> fromStart, fromEnd;
    fromStart.resize(n + 5);
    fromEnd.resize(n + 5);

    fill(all(fromStart), -1);
    fill(all(fromEnd), -1);

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;

    bool isVisited[n + 5];
    memset(isVisited, 0, sizeof(isVisited));
    pq.em(0, 1);

    while (!pq.empty()) {
        auto [value, now] = pq.top();
        pq.pop();

        if (isVisited[now]) continue;
        isVisited[now] = true;
        fromStart[now] = value;

        for (auto p : edges[now]) {
            if (isVisited[p.first]) continue;

            pq.em(p.second + value, p.first);
        }
    }

    memset(isVisited, 0, sizeof(isVisited));
    pq.em(0, n);

    while (!pq.empty()) {
        auto [value, now] = pq.top();
        pq.pop();

        if (isVisited[now]) continue;
        isVisited[now] = true;
        fromEnd[now] = value;

        for (auto p : edges[now]) {
            if (isVisited[p.first]) continue;

            pq.em(p.second + value, p.first);
        }
    }

    rep(i, 1, n) {
        if ((elevators[i] == -1) or (fromStart[i] == -1) or (fromEnd[i] == -1))
            continue;

        ll value = fromStart[i] + fromEnd[i] + elevators[i] * (k - 1);
        ans = min(ans, value);
    }

    cout << (ans == 0x7f7f7f7f7f7f7f7f ? -1 : ans);
}
