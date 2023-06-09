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

int nodeNumber, edgeNumber, nodeData[20'001];
vvi edges;

bool stop;

void input() {
    stop = false;
    memset(nodeData, -1, sizeof(nodeData));
    edges.clear();

    cin >> nodeNumber >> edgeNumber;

    edges.resize(nodeNumber + 1);

    int a, b;
    while (edgeNumber--) {
        cin >> a >> b;

        edges[a].emb(b);
        edges[b].emb(a);
    }
}

void bfs(int startNode) {
    queue<int> q;
    q.em(startNode);

    nodeData[startNode] = 0;

    int nextData, now;
    while (!q.empty()) {
        now = q.front();
        q.pop();

        nextData = (nodeData[now] == 0 ? 1 : 0);

        for (auto &i : edges[now]) {
            if (nodeData[i] == -1) {
                nodeData[i] = nextData;
                q.em(i);
            } else if (nodeData[i] != nextData) {
                cout << "NO" << endl;
                stop = true;
                return;
            }
        }
    }
}

void solve() {
    // bfs
    rep(i, 1, nodeNumber) {
        if (stop)
            return;
        if (nodeData[i] == -1)
            bfs(i);
    }

    cout << "YES" << endl;
}

int main() {
    fastio;

    int t;
    cin >> t;

    while (t--) {
        input();
        solve();
    }
}