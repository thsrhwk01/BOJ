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

// Floyd–Warshall Algorithm
const int INF = 0x3f3f3f3f;

// graph[from][to] = cost
int nodeNumber, edgeNumber, graph[105][105];

void input() {
    cin >> nodeNumber;

    cin >> edgeNumber;

    memset(graph, INF, sizeof(graph));

    int from, to, cost;
    while (edgeNumber--) {
        cin >> from >> to >> cost;

        graph[from][to] = min(graph[from][to], cost);
    }
}

void solve() {
    rep(i, 1, nodeNumber) graph[i][i] = 0;

    // Floyd-Warshall
    rep(k, 1, nodeNumber) {
        rep(i, 1, nodeNumber) {
            rep(j, 1, nodeNumber) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}

void output() {
    rep(i, 1, nodeNumber) {
        rep(j, 1, nodeNumber) {
            cout << (graph[i][j] == INF ? 0 : graph[i][j]) << ' ';
        }
        cout << endl;
    }
}

int main() {
    fastio;

    input();
    solve();
    output();
}