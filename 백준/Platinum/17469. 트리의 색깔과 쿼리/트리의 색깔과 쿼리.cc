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

int parents[100'001], parentsInfo[100'001], nodeColor[100'001], nodeNumber,
    queryNumber;

set<int> colorSet[100'001];

vii queries;

vi results;

int findSet(int x) {
    return parents[x] == x ? x : parents[x] = findSet(parents[x]);
}

void unionSet(int x, int y) {
    x = findSet(x);
    y = findSet(y);

    if (x == y)
        return;

    // Set x < y to set parents[y] = x
    if (x > y)
        swap(x, y);

    // Set bigger color set to colorSet[x]
    if (colorSet[x].size() < colorSet[y].size())
        swap(colorSet[x], colorSet[y]);

    for (int color : colorSet[y])
        colorSet[x].em(color);

    colorSet[y].clear();

    parents[y] = x;
}

int getColorSetSize(int x) {
    return colorSet[findSet(x)].size();
}

void input() {
    cin >> nodeNumber >> queryNumber;

    rep(i, 2, nodeNumber) {
        int parent;
        cin >> parent;

        parentsInfo[i] = parent;
    }

    rep(i, 1, nodeNumber) {
        int color;
        cin >> color;

        nodeColor[i] = color;
    }

    rep(i, 1, nodeNumber + queryNumber - 1) {
        int cmd, target;

        cin >> cmd >> target;

        queries.emb(cmd, target);
    }
}

void solve() {
    reverse(all(queries));

    parentsInfo[1] = 1;
    rep(i, 1, nodeNumber) {
        parents[i] = i;
        colorSet[i].em(nodeColor[i]);
    }

    for (const auto &query : queries) {
        auto [cmd, target] = query;

        switch (cmd) {
        case 1:
            unionSet(target, parentsInfo[target]);
            break;
        case 2:
            results.emb(getColorSetSize(target));
        }
    }
}

void output() {
    reverse(all(results));

    for (int result: results) cout << result << endl;
}

int main() {
    fastio;

    input();
    solve();
    output();
}