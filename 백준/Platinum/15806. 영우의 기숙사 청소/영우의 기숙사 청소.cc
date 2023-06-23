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

int n, m, k, t;

bool boards[2][301][301];

queue<pii> checkList, moldQ;

int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1}, dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

void input() {
    cin >> n >> m >> k >> t;

    int y, x;
    while (m--) {
        cin >> x >> y;

        moldQ.em(y, x);
    }
}

inline bool isOut(int y, int x) { return y < 1 or y > n or x < 1 or x > n; }

void solve() {
    queue<pii> moldQNext;

    while (t >= 0) {
        auto &board = boards[t & 1];
        auto &boardNext = boards[(t + 1) & 1];

        while (!moldQ.empty()) {
            auto [y, x] = moldQ.front();
            moldQ.pop();

            rep(i, 0, 7) {
                int ny = dy[i] + y, nx = dx[i] + x;

                if (isOut(ny, nx) or boardNext[ny][nx])
                    continue;

                boardNext[ny][nx] = true;

                moldQNext.em(ny, nx);
            }
        }

        --t;
        swap(moldQ, moldQNext);
    }
}

void output() {
    int y, x;

    while (k--) {
        cin >> x >> y;

        if (boards[0][y][x]) {
            cout << "YES";
            return;
        }
    }

    cout << "NO";
}

int main() {
    fastio;

    input();
    solve();
    output();
}