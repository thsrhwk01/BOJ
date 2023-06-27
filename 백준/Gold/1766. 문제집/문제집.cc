#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

#define endl '\n'
#define em emplace
#define emb emplace_back
#define all(x) x.begin(), x.end()
#define rep(i, from, to) for (int i = from; i <= to; ++i)
#define fastio                                                                 \
    iostream::sync_with_stdio(false);                                          \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);

// 위상 정렬?
set<int> required[32'001];
vi childs[32'001];

int n, m;

void input() {
    cin >> n >> m;

    int easy, hard;
    while (m--) {
        cin >> easy >> hard;

        required[hard].em(easy);
        childs[easy].emb(hard);
    }
}

void solve() {
    priority_queue<int, vi, greater<>> pq;

    rep(i, 1, n) {
        if (required[i].empty())
            pq.em(i);
    }

    while (!pq.empty()) {
        auto now = pq.top();
        pq.pop();

        cout << now << ' ';

        for (auto &child : childs[now]) {
            required[child].erase(now);
            
            if (required[child].empty())
                pq.em(child);
        }
    }
}

int main() {
    fastio;

    input();
    solve();
}