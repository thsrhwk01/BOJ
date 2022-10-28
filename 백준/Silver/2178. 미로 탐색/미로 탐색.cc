#include <iostream>
#include <queue>

using namespace std;

int solve(short** maze, short end_x, short end_y) {
    queue<pair<pair<short, short>, short>> q;
    q.emplace(make_pair(0, 0), 1);

    while (!q.empty()) {
        auto x = q.front().first.first;
        auto y = q.front().first.second;
        auto cnt = q.front().second;
        q.pop();

        if (x == end_x && y == end_y) return cnt;

        else {
            if (x-1 >= 0 && maze[x-1][y] == -1) {
                maze[x-1][y] = cnt + 1;
                q.emplace(make_pair(x - 1, y), cnt + 1);
            }
            if (y-1 >= 0 && maze[x][y-1] == -1) {
                maze[x][y-1] = cnt + 1;
                q.emplace(make_pair(x, y - 1), cnt + 1);
            }
            if (x+1 <= end_x && maze[x+1][y] == -1) {
                maze[x+1][y] = cnt + 1;
                q.emplace(make_pair(x + 1, y), cnt + 1);
            }
            if (y+1 <= end_y && maze[x][y+1] == -1) {
                maze[x][y+1] = cnt + 1;
                q.emplace(make_pair(x, y + 1), cnt + 1);
            }
        }
    }
}

int main() {
    short n, m; cin >> n >> m;
    short** maze;
    maze = new short* [n];

    for (int i = 0; i < n; ++i) {
        maze[i] = new short [m];
        string tmp; cin >> tmp;
        for (int j = 0; j < m; ++j) {
            maze[i][j] = tmp[j] - 50;
        }
    }

    cout << solve(maze, n - 1, m - 1);
}