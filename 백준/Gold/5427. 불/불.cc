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

int n, m, sec;

bool possible;

char board[1000][1000];

array<array<bool, 1000>, 1000> isVisited;

queue<pii> fireQ, personQ;

int dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1};

inline bool isOut(int y, int x) { return y < 0 or y >= n or x < 0 or x >= m; }

inline bool isBorder(int y, int x) {
    return y == 0 or y == n - 1 or x == 0 or x == m - 1;
}

void input() {
    cin >> m >> n;
    fireQ = queue<pii>();
    personQ = queue<pii>();

    rep(i, 0, n - 1) {
        rep(j, 0, m - 1) {
            cin >> board[i][j];

            switch (board[i][j]) {
            case '*':
                fireQ.em(i, j);
                break;
            case '@':
                personQ.em(i, j);
                board[i][j] = '.';
            }
        }
    }
}

void solve() {
    sec = 0;
    possible = false;
    for_each(all(isVisited), [](auto &row) { fill(all(row), false); });

    isVisited[personQ.front().first][personQ.front().second] = true;

    queue<pii> fireQNext, personQNext;

    while (!personQ.empty()) {
        ++sec;

        while (!fireQ.empty()) {
            auto [y, x] = fireQ.front();

            fireQ.pop();

            rep(i, 0, 3) {
                int ny = dy[i] + y, nx = dx[i] + x;

                if (isOut(ny, nx) or board[ny][nx] != '.')
                    continue;

                board[ny][nx] = '*';

                fireQNext.em(ny, nx);
            }
        }

        while (!personQ.empty()) {
            auto [y, x] = personQ.front();

            personQ.pop();

            if (isBorder(y, x)) {
                possible = true;
                return;
            }

            rep(i, 0, 3) {
                int ny = dy[i] + y, nx = dx[i] + x;

                if (isVisited[ny][nx] or board[ny][nx] != '.')
                    continue;

                isVisited[ny][nx] = true;

                personQNext.em(ny, nx);
            }
        }

        swap(fireQ, fireQNext);
        swap(personQ, personQNext);
    }
}

void output() {
    if (possible)
        cout << sec;
    else
        cout << "IMPOSSIBLE";

    cout << endl;
}

int main() {
    fastio;

    int t;
    cin >> t;

    while (t--) {
        input();
        solve();
        output();
    }
}