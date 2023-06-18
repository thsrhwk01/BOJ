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

int from, to, sec, cnt;

bool isVisited[100'001];

inline bool isOut(int x) { return x < 0 or x > 100'000; }

void input() { cin >> from >> to; }

void solve() {
    queue<int> q, nq, lockq;

    q.em(from);

    while (true) {
        bool stop = false;

        while (!q.empty()) {
            int now = q.front();
            q.pop();

            if (isVisited[now])
                continue;

            if (now == to) {
                ++cnt;
                stop = true;
            }

            lockq.em(now);

            int tmp = now - 1;
            if (!isOut(tmp)) {
                nq.em(tmp);
            }

            tmp = now + 1;
            if (!isOut(tmp)) {
                nq.em(tmp);
            }

            tmp = now * 2;
            if (!isOut(tmp)) {
                nq.em(tmp);
            }
        }
        while (!lockq.empty()) {
            isVisited[lockq.front()] = true;
            lockq.pop();
        }

        if (stop)
            break;

        ++sec;
        swap(q, nq);
    }
}

void output() { cout << sec << endl << cnt; }

int main() {
    fastio;

    input();
    solve();
    output();
}