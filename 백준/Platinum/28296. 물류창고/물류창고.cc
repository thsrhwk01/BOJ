#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using tiii = tuple<int, int, int>;

#define endl '\n'
#define em emplace
#define emb emplace_back
#define all(x) x.begin(), x.end()
#define rep(i, from, to) for (int i = from; i <= to; ++i)
#define fastio                                                                 \
    iostream::sync_with_stdio(false);                                          \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);

int storageNumber, companyNumber, edgeNumber, parents[100'001];

long long results[50'001];

map<int, long long> connectedStorage[100'001];

priority_queue<tiii> pq;

int findSet(int x) {
    return parents[x] == x ? x : parents[x] = findSet(parents[x]);
}

void unionSet(int x, int y, long long weight) {
    x = findSet(x);
    y = findSet(y);

    if (x == y)
        return;

    // merge y to x
    if (x > y)
        swap(x, y);

    parents[y] = x;

    if (connectedStorage[x].size() < connectedStorage[y].size())
        swap(connectedStorage[x], connectedStorage[y]);

    for (auto &p : connectedStorage[y]) {
        auto [company, cnt] = p;

        results[company] += weight * connectedStorage[x][company] * cnt;
        connectedStorage[x][company] += cnt;
    }

    connectedStorage[y].clear();
}

bool isConnected(int x, int y) { return findSet(x) == findSet(y); }

void input() {
    cin >> storageNumber >> companyNumber >> edgeNumber;

    rep(i, 1, storageNumber) {
        int company;
        cin >> company;

        connectedStorage[i][company] = 1;
    }

    rep(i, 1, edgeNumber) {
        int a, b, weight;
        cin >> a >> b >> weight;

        pq.em(weight, a, b);
    }
}

void solve() {
    rep(i, 1, storageNumber) {
        parents[i] = i;
    }

    while (!pq.empty()) {
        auto [weight, a, b] = pq.top();
        pq.pop();

        if (isConnected(a, b)) continue;

        unionSet(a, b, weight);
    }
}

void output() {
    rep(i, 1, companyNumber) {
        cout << results[i] << endl;
    }
}

int main() {
    fastio;

    input();
    solve();
    output();
}