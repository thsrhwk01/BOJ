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

int n, p, mounts[100'005], ans;

vi edge[100'005];
bool isVisited[100'005];

int dfs(int node) {
    int temp = 0;

    for (int nextNode : edge[node]) {
        if (isVisited[nextNode])
            continue;
        isVisited[nextNode] = true;
        temp += dfs(nextNode);
    }

    temp += mounts[node];

    return temp < 0 ? temp : 0;
}

int main() {
    fastio;

    cin >> n >> p;

    rep(i, 1, n) { cin >> mounts[i]; }
    rep(i, 1, n) {
        int tmp;
        cin >> tmp;
        mounts[i] -= tmp;
    }

    rep(i, 1, n - 1) {
        int from, to;
        cin >> from >> to;

        edge[from].emb(to);
        edge[to].emb(from);
    }

    isVisited[p] = true;
    ans = dfs(p);

    cout << -ans;
}