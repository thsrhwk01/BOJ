#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;

    vector<vector<pair<int, int>>> edges(n + 1);

    int l = 0, r = 0x3f3f3f3f;
    bool isAble = false;

    for (int i = 0; i < m; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;

        edges[from].emplace_back(to, weight);
        edges[to].emplace_back(from, weight);
    }

    while (r > l + 1) {
        auto mid = (r + l) / 2;

        vector<bool> isVisited(n + 1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, a);

        while (!pq.empty()) {
            auto [sum, x] = pq.top();
            pq.pop();

            if (isVisited[x]) {
                continue;
            }
            isVisited[x] = true;

            if (x == b) {
                isAble = true;

                break;
            }

            for (auto [y, weight] : edges[x]) {
                if (isVisited[y] or weight > mid or weight + sum > c) {
                    continue;
                }

                pq.emplace(sum + weight, y);
            }
        }

        if (isVisited[b]) {
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << (isAble ? r : -1);

    return 0;
}