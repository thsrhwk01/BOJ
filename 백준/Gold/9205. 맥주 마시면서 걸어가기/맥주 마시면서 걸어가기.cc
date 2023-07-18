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

int conveniNumber;

// 0: home, 1 ~ conveniNumber: convenient
vii locationList(101);

pii endLocation;

vi graph[101];
bool isVisited[101], ans;

inline int getDist(const pii &a, const pii &b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void input() {
    cin >> conveniNumber;

    rep(i, 0, conveniNumber) cin >> locationList[i].first >>
        locationList[i].second;

    cin >> endLocation.first >> endLocation.second;
}

void dfs(int idx) {
    if (ans)
        return;

    for (auto i : graph[idx]) {
        if (i == -1) {
            ans = true;
            return;
        }

        if (isVisited[i])
            continue;

        isVisited[i] = true;
        dfs(i);
    }
}

void solve() {
    for (auto &ls : graph) {
        ls.clear();
    }

    rep(i, 0, conveniNumber) {
        rep(j, i + 1, conveniNumber) {
            if (getDist(locationList[i], locationList[j]) <= 1000) {
                graph[i].emb(j);
                graph[j].emb(i);
            }
        }

        if (getDist(locationList[i], endLocation) <= 1000) {
            graph[i].emb(-1);
        }
    }

    memset(isVisited, 0, sizeof(isVisited));
    ans = false;

    isVisited[0] = true;
    dfs(0);
}

void output() { cout << (ans ? "happy" : "sad") << endl; }

int main() {
    fastio;

    int t;
    cin >> t;

    while (t--) {
        input();
        solve();
        output();
    }
}
