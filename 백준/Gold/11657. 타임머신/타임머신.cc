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

// Shortest Path Faster Algorithm (SPFA)
// Use to find the shortest distance from one node to all other nodes
// Can also be used with negative edges
const ll INF = 0x7f7f7f7f;

int nodeNumber, edgeNumber;

// edges[from] = {{to, weight}}
vector<pair<ll, ll>> edges[501];

array<ll, 501> dist, visitCount;

bool inQ[501], negativeCycleFound;

void input() {
    cin >> nodeNumber >> edgeNumber;

    int from, to, weight;
    rep(i, 1, edgeNumber) {
        cin >> from >> to >> weight;

        edges[from].emb(to, weight);
    }
}

void solve() {
    fill(all(dist), INF);

    dist[1] = 0;

    queue<int> q;
    q.em(1);
    inQ[1] = true;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        inQ[now] = false;

        for (auto &edge : edges[now]) {
            auto [nextNode, weight] = edge;

            if (dist[nextNode] <= dist[now] + weight)
                continue;

            dist[nextNode] = dist[now] + weight;

            if (inQ[nextNode])
                continue;

            inQ[nextNode] = true;
            q.em(nextNode);

            ++visitCount[nextNode];
            if (visitCount[nextNode] >= nodeNumber) {
                negativeCycleFound = true;
                return;
            }
        }
    }
}

void output() {
    if (negativeCycleFound)
        cout << -1;
    else
        rep(i, 2, nodeNumber)
            cout << (dist[i] != INF ? dist[i] : -1) << endl;
}

int main() {
    fastio;

    input();
    solve();
    output();
}