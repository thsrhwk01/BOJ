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

int main() {
    fastio;

    int edgeNumber, nodeNumber, forbiddenNumber;
    cin >> edgeNumber >> nodeNumber >> forbiddenNumber;

    int startNode, endNode;
    cin >> startNode >> endNode;

    vii roads[nodeNumber];

    rep(i, 1, edgeNumber) {
        int from, to, cost;
        cin >> from >> to >> cost;

        roads[from].emb(to, cost);
    }

    set<tiii> forbiddenRoads;
    rep(i, 1, forbiddenNumber) {
        int a, b, c;
        cin >> a >> b >> c;

        forbiddenRoads.em(a, b, c);
    }

    auto cmp = [](tiii l, tiii r) { return get<0>(l) > get<0>(r); };

    priority_queue<tiii, vector<tiii>, decltype(cmp)> pq;
    pq.em(0, startNode, -1);

    set<pii> usedRoad;

    while (!pq.empty()) {
        auto [costSum, now, before] = pq.top();
        pq.pop();

        if (now == endNode) {
            cout << costSum;
            return 0;
        }

        if (usedRoad.find(make_pair(before, now)) != usedRoad.end()) {
            continue;
        }
        usedRoad.em(before, now);

        for (const auto &road : roads[now]) {
            auto [nextNode, cost] = road;

            if (usedRoad.find(make_pair(now, nextNode)) != usedRoad.end()) {
                continue;
            }

            if (forbiddenRoads.find(make_tuple(before, now, nextNode)) !=
                forbiddenRoads.end()) {
                continue;
            }

            pq.em(costSum + cost, nextNode, now);
        }
    }

    cout << -1;
    return 0;
}