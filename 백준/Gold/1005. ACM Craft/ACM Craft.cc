//
// Created by 99woo on 2023-01-02.
//

#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;
using vii = vector<pii>;
using ll = long long;

#define endl '\n'
#define em emplace
#define emb emplace_back
#define all(x) x.begin(), x.end()
#define fastio iostream::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

vector<int> tech_time, remain_techs;
vector<vector<int>> tech_tree;


int n, k, what;

void input() {
    tech_tree.clear();
    tech_time.clear();
    remain_techs.clear();

    cin >> n >> k;

    tech_time.resize(n + 1);
    tech_tree.resize(n + 1);
    remain_techs.resize(n + 1);

    for (int i = 1; i < n + 1; ++i) {
        cin >> tech_time[i];
    }

    int from, to;
    for (int i = 0; i < k; ++i) {
        cin >> from >> to;
        tech_tree[from].emb(to);

        ++remain_techs[to];
    }

    cin >> what;
}

void solve() {
    priority_queue<pii, vector<pii>, greater<>> pq;
    for (int i = 1; i < n + 1; ++i)
        if (remain_techs[i] == 0)
            pq.emplace(tech_time[i], i);

    while (!pq.empty()) {
        auto now = pq.top();
        pq.pop();

        if (now.second == what) {
            cout << now.first << endl;
            return;
        }

        for (auto next_tech: tech_tree[now.second]) {
            --remain_techs[next_tech];
            if (remain_techs[next_tech] == 0) pq.em(now.first + tech_time[next_tech], next_tech);
        }
    }
}

int main() {
    fastio

    int t;
    cin >> t;

    while (t--) {
        input();
        solve();
    }
}