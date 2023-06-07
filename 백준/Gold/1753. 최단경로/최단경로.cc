#include <bits/stdc++.h>

using namespace std;

using ll  = long long;
using vi  = vector<int>;
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
    cout.tie(nullptr);                                                         \


// Dijkstra Algorithm
const int INF = 0x7f7f7f7f;

int nodeNumber, edgeNumber, startNode, result[20001];

vii edges[20001];

// Dijkstra function
void dijkstra() {
    // Initialize result with infinite
    memset(result, INF, sizeof(result));

    // {cost, to}
    priority_queue<pii, vii, greater<>> pq;
    pq.em(0, startNode);
    
    while (!pq.empty()) {
        auto [costNow, nodeNow] = pq.top();
        pq.pop();

        if (result[nodeNow] != INF) continue;
        result[nodeNow] = costNow;
        
        for (const auto &edge : edges[nodeNow]) {
            auto [nextNode, nextCost] = edge;
            nextCost += costNow;
            
            if(result[nextNode] != INF) continue;

            pq.em(nextCost, nextNode);
        }
    }
}

void input() {
    cin >> nodeNumber >> edgeNumber >> startNode;

    int from, to, cost;

    while (edgeNumber--) {
        cin >> from >> to >> cost;

        edges[from].emb(to, cost);
    }
}

void solve() {
    dijkstra();
}

void output() {
    rep(i, 1, nodeNumber) {
        if (result[i] == INF) cout << "INF";
        else cout << result[i];

        cout << endl;
    }
}

int main() {
    fastio;

    input();
    solve();
    output();
}