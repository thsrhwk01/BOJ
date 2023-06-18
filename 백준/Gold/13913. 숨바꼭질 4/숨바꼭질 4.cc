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

int from, to, fromTrack[100'001];

inline bool isOut(int x) { return x < 0 || x > 100'000; }

void input() { cin >> from >> to; }

void solve() {
    memset(fromTrack, -1, sizeof(fromTrack));

    queue<int> q;

    q.em(from);

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        if (now == to)
            return;

        int tmp = now - 1;

        if (!isOut(tmp) && fromTrack[tmp] == -1) {
            fromTrack[tmp] = now;
            q.em(tmp);
        }

        tmp = now + 1;

        if (!isOut(tmp) && fromTrack[tmp] == -1) {
            fromTrack[tmp] = now;
            q.em(tmp);
        }

        tmp = now * 2;

        if (!isOut(tmp) && fromTrack[tmp] == -1) {
            fromTrack[tmp] = now;
            q.em(tmp);
        }
    }
}

void output() {
    vi history;

    while (true) {
        history.emb(to);
        if (to == from)
            break;

        to = fromTrack[to];
    }

    reverse(all(history));

    cout << history.size() - 1 << endl;
    for (auto &i : history)
        cout << i << ' ';
}

int main() {
    fastio;

    input();
    solve();
    output();
}