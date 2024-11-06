#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

vector<int> parent;

int findSet(int x) {
    return x == parent[x] ? x : parent[x] = findSet(parent[x]);
}

void unionSet(int x, int y) {
    x = findSet(x);
    y = findSet(y);

    parent[max(x, y)] = min(x, y);
}

bool isConnected(int x, int y) { return findSet(x) == findSet(y); }

int main() {
    int v, e;
    cin >> v >> e;

    parent.resize(v + 5);

    iota(parent.begin(), parent.end(), 0);

    vector<tuple<int, int, int>> edges;
    while (e--) {
        int from, to, weight;
        cin >> from >> to >> weight;

        edges.emplace_back(weight, from, to);
    }

    sort(edges.begin(), edges.end());

    long long ans = 0;

    for (const auto &[weight, from, to] : edges) {
        if (isConnected(from, to)) {
            continue;
        }

        ans += weight;

        unionSet(from, to);
    }

    cout << ans;
}