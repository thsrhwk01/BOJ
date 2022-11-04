//
// Created by woo-young Choi on 2022/11/04.
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

queue<int> nowq, nextq;
int n, k, t = 0;

bool visited[100'010];

void input() {
    cin >> n >> k;
}

void emplacing(int x) {
    if (x != 0 && x * 2 < 100'010) {
        if (!visited[x * 2]) {
            nowq.em(x * 2);
            visited[x * 2] = true;
        }
    }
    if (x > 0 && !visited[x - 1]) {
        nextq.em(x - 1);
        visited[x - 1] = true;
    }
    if (x < 100'000 && !visited[x + 1]) {
        nextq.em(x + 1);
        visited[x - 1] = true;
    }
}

void solve() {
    if (n == k) return;
    visited[n] = true;
    emplacing(n);

    int now;
    while (true) {
        if (nowq.empty()) {
            ++t;
            nowq.swap(nextq);
        }
        
        now = nowq.front();

        nowq.pop();

        if (now == k) return;

        emplacing(now);
    }
}

void output() {
    cout << t;
}

int main() {
    fastio

    input();
    solve();
    output();
}
