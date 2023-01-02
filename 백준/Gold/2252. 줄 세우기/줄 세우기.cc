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

int n, m;

vector<vector<int>> next_person;
vector<int> remain_person_cnt;

void input() {
    cin >> n >> m;

    next_person.resize(n + 1);
    remain_person_cnt.resize(n + 1);

    int bef, aft;
    while (m--) {
        cin >> bef >> aft;
        ++remain_person_cnt[aft];

        next_person[bef].emb(aft);
    }
}

void solve() {
    queue<int> q;

    for (int i = 1; i < next_person.size(); ++i)
        if (remain_person_cnt[i] == 0)
            q.em(i);

    while(!q.empty()) {
        auto now = q.front();
        q.pop();

        cout << now << ' ';

        for (auto next_p: next_person[now]) {
            --remain_person_cnt[next_p];

            if (remain_person_cnt[next_p] == 0) q.em(next_p);
        }
    }
}

int main() {
    fastio

    input();
    solve();
}