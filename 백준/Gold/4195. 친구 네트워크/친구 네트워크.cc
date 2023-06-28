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

int parents[200'001], friendsCnt[200'001], ans;

int findSet(int x) {
    return parents[x] == x ? x : parents[x] = findSet(parents[x]);
}

void unionSet(int x, int y) {
    x = findSet(x);
    y = findSet(y);

    if (x == y) return;

    parents[max(x, y)] = min(x, y);
    friendsCnt[min(x, y)] += friendsCnt[max(x, y)];
}

bool isConnected(int x, int y) { return findSet(x) == findSet(y); }

void solve() {
    int n;
    cin >> n;

    int idxCnt = 0;
    unordered_map<string, int> name2idx;

    rep(i, 0, 200'000) {
        parents[i] = i;
        friendsCnt[i] = 1;
    }

    string a, b;
    while (n--) {
        cin >> a >> b;

        if (name2idx.find(a) == name2idx.end())
            name2idx[a] = idxCnt++;

        if (name2idx.find(b) == name2idx.end())
            name2idx[b] = idxCnt++;

        unionSet(name2idx[a], name2idx[b]);

        cout << friendsCnt[findSet(parents[name2idx[a]])] << endl;
    }
}

int main() {
    fastio;

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}