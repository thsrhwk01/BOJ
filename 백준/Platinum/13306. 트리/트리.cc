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

int parents[200'001], parentsSaved[200'001];

int findSet(int x) {
    return parents[x] == x ? x : parents[x] = findSet(parents[x]);
}

void unionSet(int x, int y) {
    x = findSet(x);
    y = findSet(y);

    parents[max(x, y)] = min(x, y);
}

bool isConnected(int x, int y) { return findSet(x) == findSet(y); }

int nodeNumber, queryNumber;

stack<tuple<int, int, int>> cmds;
stack<bool> results;

void solve() {
    cin >> nodeNumber >> queryNumber;

    parentsSaved[1] = 1;
    parents[1] = 1;

    rep(i, 2, nodeNumber) {
        parents[i] = i;
        
        int parent;
        cin >> parent;

        parentsSaved[i] = parent;
    }

    rep(i, 1, nodeNumber + queryNumber - 1) {
        int cmd, a, b;

        cin >> cmd;
        switch (cmd) {
        case 0:
            cin >> a;
            cmds.em(cmd, a, 0);
            break;
        case 1:
            cin >> a >> b;
            cmds.em(cmd, a, b);
            break;
        }
    }

    while (!cmds.empty()) {
        auto [cmd, a, b] = cmds.top();
        cmds.pop();

        switch (cmd) {
        case 0:
            unionSet(a, parentsSaved[a]);
            break;
        case 1:
            results.emplace(isConnected(a, b));
            break;
        }
    }
}

void output() {
    while (!results.empty()) {
        cout << (results.top() ? "YES" : "NO") << endl;
        results.pop();
    }
}

int main() {
    fastio;

    solve();
    output();
}
