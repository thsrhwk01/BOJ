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
#define fastio                                                                 \
    iostream::sync_with_stdio(false);                                          \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);

vi nodes[10001];
int nodeCnt, edgeCnt, nodeParent[10001], nodeID;
bool finished[10001];
vvi SCC;

stack<int> stk;

void input() {
    //fstream cin("input.txt");
    cin >> nodeCnt >> edgeCnt;

    int from, to;
    while (edgeCnt--) {
        cin >> from >> to;

        nodes[from].emb(to);
    }
    //cin.close();
}

int dfs(int node) {
    nodeParent[node] = ++nodeID;
    stk.em(node);

    int parent = nodeParent[node];

    for (auto nextNode : nodes[node]) {
        if (nodeParent[nextNode] == 0)
            parent = min(parent, dfs(nextNode));
        else if (!finished[nextNode])
            parent = min(parent, nodeParent[nextNode]);
    }

    if (parent == nodeParent[node]) {
        vi tempSCC;
        while (true) {
            int child = stk.top();
            stk.pop();
            tempSCC.emb(child);
            finished[child] = true;
            if (child == node)
                break;
        }

        sort(all(tempSCC));

        SCC.emb(tempSCC);
    }

    return parent;
}

void solve() {
    for (int i = 1; i <= nodeCnt; i++)
        if (nodeParent[i] == 0)
            dfs(i);

    sort(all(SCC));
}

void output() {
    cout << SCC.size() << endl;
    for (const auto &scc : SCC) {
        for (const auto &node : scc)
            cout << node << ' ';
        cout << -1 << endl;
    }
}

int main() {
    fastio;

    input();
    solve();
    output();
}