#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

unordered_set<int> infected;

void infecting(const vector<unordered_set<int>>& nodes, int node) {
    for (const auto& next_node : nodes[node]) {
        if (infected.find(next_node) == infected.end()) {
            infected.emplace(next_node);
            infecting(nodes, next_node);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int node_n, edge_n; cin >> node_n >> edge_n;
    vector<unordered_set<int>> nodes(node_n);

    while (edge_n--) {
        int from, to; cin >> from >> to;
        nodes[from - 1].emplace(to - 1);
        nodes[to - 1].emplace(from - 1);
    }

    infected.emplace(0);
    infecting(nodes, 0);

    cout << infected.size() - 1;
}