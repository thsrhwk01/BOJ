#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vii = vector<pii>;
using vll = vector<pll>;

#define endl '\n'
#define em emplace
#define emb emplace_back
#define all(x) x.begin(), x.end()
#define rep(i, from, to) for (int i = from; i <= to; ++i)
#define fastio                                                                 \
    iostream::sync_with_stdio(false);                                          \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);

ll cityParent[50001], cityCount, startCity, ans;

priority_queue<tuple<int, int, int>> pq;
vll cityEdge[50001];
bool isVisited[50001];

int getParent(int city) {
    if (city == cityParent[city])
        return city;
    return getParent(cityParent[city]);
}

void unionParent(int city1, int city2) {
    city1 = getParent(city1);
    city2 = getParent(city2);

    if (city1 < city2)
        swap(city1, city2);

    cityParent[city1] = city2;
}

bool isSameParent(int city1, int city2) {
    return getParent(city1) == getParent(city2);
}

void input() {
    ll edgeCount;
    cin >> cityCount >> edgeCount;

    int cost, from, to;
    while (edgeCount--) {
        cin >> from >> to >> cost;

        pq.em(cost, from, to);
    }

    cin >> startCity;
}

void mst() {
    iota(cityParent, cityParent + 50001, 0);

    while (!pq.empty()) {
        int cost, from, to;
        tie(cost, from, to) = pq.top();
        pq.pop();

        if (isSameParent(from, to)) continue;

        unionParent(from, to);
        cityEdge[from].emb(to, cost);
        cityEdge[to].emb(from, cost);
        ans += cost;
    }
}

ll dfs(int city) {
    isVisited[city] = true;

    ll ret = 0;

    for (auto edge: cityEdge[city]) {
        int nextCity;
        ll cost;
        tie(nextCity, cost) = edge;

        if (isVisited[nextCity]) continue;

        ret = max(ret, cost + dfs(nextCity));
    }

    return ret;
}

void solve() {
    mst();

    ans *= 2;
    
    ans -= dfs(startCity);
}

void output() {
    cout << ans;
}

int main() {
    fastio;

    input();
    solve();
    output();
}