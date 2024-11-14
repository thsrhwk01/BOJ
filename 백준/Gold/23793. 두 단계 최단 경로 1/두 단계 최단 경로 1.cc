#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

#define endl '\n'

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> edges(n + 1);

    for (int i = 0; i < m; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;

        edges[from].emplace_back(to, weight);
    }

    int x, y, z;
    cin >> x >> y >> z;

    vector<bool> isVisited(n + 1);

    auto cmp = [](auto x, auto y) {
        swap(x.first, y.first);
        return x < y;
    };

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, decltype(cmp)> pq(cmp);
    ll ans1 = -1, ans2 = -1, sumXY = -1, sumYZ = -1;

    pq.emplace(0, x);

    while (!pq.empty()) {
        auto [sum, node] = pq.top();
        pq.pop();

        if (isVisited[node]) {
            continue;
        }
        isVisited[node] = true;

        if (node == y) {
            sumXY = sum;

            break;
        }

        for (const auto &[nNode, weight] : edges[node]) {
            if (isVisited[nNode]) {
                continue;
            }

            pq.emplace(sum + weight, nNode);
        }
    }

    while (!pq.empty()) {
        pq.pop();
    }

    fill(isVisited.begin(), isVisited.end(), false);
    pq.emplace(0, y);

    while (!pq.empty()) {
        auto [sum, node] = pq.top();
        pq.pop();

        if (isVisited[node]) {
            continue;
        }
        isVisited[node] = true;

        if (node == z) {
            sumYZ = sum;

            break;
        }

        for (const auto &[nNode, weight] : edges[node]) {
            if (isVisited[nNode]) {
                continue;
            }

            pq.emplace(sum + weight, nNode);
        }
    }

    while (!pq.empty()) {
        pq.pop();
    }

    if(sumXY != -1 and sumYZ != -1) {
        ans1 = sumXY + sumYZ;
    }

    fill(isVisited.begin(), isVisited.end(), false);
    pq.emplace(0, x);

    while (!pq.empty()) {
        auto [sum, node] = pq.top();
        pq.pop();

        if (isVisited[node]) {
            continue;
        }
        isVisited[node] = true;

        if (node == z) {
            ans2 = sum;

            break;
        }

        for (const auto &[nNode, weight] : edges[node]) {
            if (isVisited[nNode] or nNode == y) {
                continue;
            }

            pq.emplace(sum + weight, nNode);
        }
    }

    cout << ans1 << ' ' << ans2;

    return 0;
}