//
// Created by woo-young Choi on 2022/11/09.
//

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define pii pair<int, int>
#define vii vector<pii>
#define ll long long

#define em emplace
#define emb emplace_back
#define range(x) x.begin(), x.end()
#define fastio iostream::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

vector<int> vec, knowing;
vector<vector<int>> parties;
int people, party, know, ans = 0;

int getParent(int x) {
    return (vec[x] == x ? x : getParent(vec[x]));
}

bool isSameParent(int x, int y) {
    return getParent(x) == getParent(y);
}

void unionParent(int x, int y) {
    x = getParent(x);
    y = getParent(y);

    vec[max(x, y)] = min(x, y);
}

void input() {
    cin >> people >> party;

    vec.resize(people + 1);
    iota(range(vec), 0);

    cin >> know;
    knowing.resize(know);
    for (auto &i: knowing) cin >> i;

    parties.resize(party);
    for (auto &p: parties) {
        int n;
        cin >> n;
        p.resize(n);

        for (auto &i: p) {
            cin >> i;
        }
    }
}

void solve() {
    for (const auto &p: parties) {
        for (int i = 1; i < p.size(); ++i) {
            unionParent(p[i - 1], p[i]);
        }
    }

    for (auto &i: knowing) i = getParent(i);

    for (const auto &p: parties) {
        [&] {
            for (const auto &i: p) {
                if (find(range(knowing), getParent(i)) != knowing.end()) return;
            }

            ++ans;
        }();
    }
}

void output() {
    cout << ans;
}

int main() {
    fastio

    input();
    solve();
    output();
}
