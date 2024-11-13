#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<vector<pair<long long, long long>>> vec(n + 1);

    for (int i = 0; i < n - 1; i++) {
        long long from, to, weight;
        cin >> from >> to >> weight;

        vec[from].emplace_back(to, weight);
        vec[to].emplace_back(from, weight);
    }

    long long ans = -1;
    vector<bool> isVisited(n + 1);
    queue<pair<long long, long long>> q;
    
    q.emplace(1, 0);
    isVisited[1] = true;

    while (!q.empty()) {
        auto [node, weightSum] = q.front();
        q.pop();

        ans = max(ans, weightSum);

        for (const auto &edge: vec[node]) {
            auto [nNode, weight] = edge;
            
            if (isVisited[nNode]) {
                continue;
            }
            isVisited[nNode] = true;

            q.emplace(nNode, weightSum + weight);
        }
    }

    cout << ans;

    return 0;
}