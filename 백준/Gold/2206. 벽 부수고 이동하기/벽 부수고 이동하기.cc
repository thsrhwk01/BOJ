#include <iostream>
#include <queue>

using namespace std;

struct progress {
    int x, y, time = 0;
    bool crushed = false;

    progress(int x, int y, int time, bool crushed) : x(x), y(y), time(time), crushed(crushed) {}
};

int n, m, ans = -1;
int **map;
bool **visited;
bool **visited_crush;

int xs[3] = {-1, 0, 1}, ys[3] = {-1, 0, 1};

void input() {
    cin >> n >> m;

    map = new int *[n];
    visited = new bool *[n];
    visited_crush = new bool *[n];

    string tmp;
    for (int i = 0; i < n; ++i) {
        map[i] = new int[m];
        visited[i] = new bool[m];
        visited_crush[i] = new bool[m];
        cin >> tmp;
        for (int j = 0; j < m; ++j) {
            map[i][j] = tmp[j] - '0';
        }
    }
}

void solve() {
    queue<progress> q;

    q.emplace(0, 0, 1, false);
    visited[0][0] = true;

    while (!q.empty()) {
        auto now = q.front();
        q.pop();

        if (now.x == n - 1 && now.y == m - 1) {
            ans = now.time;
            return;
        }

        for (const auto &x: xs) {
            for (const auto &y: ys) {
                if ((x != 0 && y != 0) || (x == 0 && y == 0)) continue;
                if (now.x + x < 0 || now.y + y < 0 ||
                    now.x + x >= n || now.y + y >= m)
                    continue;

                if (now.crushed && (visited_crush[now.x + x][now.y + y] || map[now.x + x][now.y + y] == 1)) continue;
                if (!now.crushed && visited[now.x + x][now.y +y]) continue;

                if (map[now.x + x][now.y + y] == 1 && !now.crushed) {
                    visited_crush[now.x + x][now.y + y] = true;
                    q.emplace(now.x + x, now.y + y, now.time + 1, true);
                } else {
                    if (now.crushed) visited_crush[now.x + x][now.y + y] = true;
                    else visited[now.x + x][now.y + y] = true;
                    q.emplace(now.x + x, now.y + y, now.time + 1, now.crushed);
                }
            }
        }
    }
}

void output() {
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    solve();
    output();
}