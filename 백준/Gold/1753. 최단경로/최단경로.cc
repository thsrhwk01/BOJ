//
// Created by 99woo on 2022-08-06.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

template <typename T>
struct cmp {
    bool operator() (const T& rhs, const T& lhs) { return rhs.second > lhs.second; }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, e, start; cin >> n >> e >> start;

    vector<vector<pair<int, int>>> nodes(n+1);

    while (e--) {
        int beg, end, val; cin >> beg >> end >> val;
        nodes[beg].emplace_back(end, val);
    }

    unordered_map<int, int> result;

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp<pair<int, int>>> q;
    q.emplace(start, 0);

    while (!q.empty()) {
        const auto curr = q.top();
        q.pop();

        if (result.find(curr.first) != result.end()) continue;
        result[curr.first] = curr.second;

        for (const auto& it : nodes[curr.first]) {
            q.emplace(it.first, curr.second + it.second);
        }
    }

    for (int i = 1 ; i < n + 1 ; ++i) {
        if (result.find(i) == result.end()) {
            cout << "INF\n";
        } else {
            cout << result[i] << '\n';
        };
    }
}