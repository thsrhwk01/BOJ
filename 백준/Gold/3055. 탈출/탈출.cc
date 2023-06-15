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

char board[51][51];
bool isVisited[51][51];

int n, m, ans;

// up down left right
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

queue<pii> sonicQ, waterQ;

void input() {
    cin >> n >> m;

    rep(i, 0, n - 1) {
        rep(j, 0, m - 1) {
            cin >> board[i][j];

            switch (board[i][j]) {
            case '*':
                waterQ.em(i, j);
                break;

            case 'S':
                board[i][j] = '.';
                sonicQ.em(i, j);
                break;
            }
        }
    }
}

inline bool isOut(int y, int x) {
    return y < 0 or y >= n or x < 0 or x >= m or board[y][x] == 'X' or
           board[y][x] == '*';
}

void solve() {
    while (!sonicQ.empty()) {
        ++ans;

        queue<pii> sonicQNext, waterQNext;

        // Moving water
        while (!waterQ.empty()) {
            auto [y, x] = waterQ.front();
            waterQ.pop();

            rep(i, 0, 3) {
                int ny = dy[i] + y, nx = dx[i] + x;

                if (isOut(ny, nx))
                    continue;
                if (board[ny][nx] == 'D')
                    continue;

                board[ny][nx] = '*';
                waterQNext.em(ny, nx);
            }
        }

        // Moving hedgehog
        while (!sonicQ.empty()) {
            auto [y, x] = sonicQ.front();
            sonicQ.pop();

            rep(i, 0, 3) {
                int ny = dy[i] + y, nx = dx[i] + x;

                if (isOut(ny, nx))
                    continue;
                if (isVisited[ny][nx])
                    continue;
                    
                if (board[ny][nx] == 'D')
                    return;

                isVisited[ny][nx] = true;
                sonicQNext.em(ny, nx);
            }
        }

        swap(sonicQ, sonicQNext);
        swap(waterQ, waterQNext);
    }

    ans = -1;
}

void output() {
    if (ans == -1)
        cout << "KAKTUS";
    else
        cout << ans;
}

int main() {
    fastio;

    input();
    solve();
    output();
}