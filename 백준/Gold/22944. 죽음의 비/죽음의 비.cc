#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, h, d;
    cin >> n >> h >> d;

    vector<vector<char>> vec(n, vector<char>(n));

    pair<int, int> sPoint;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; j++) {
            cin >> vec[i][j];

            if (vec[i][j] == 'S') {
                sPoint.first = i;
                sPoint.second = j;
            }
        }
    }

    vector<vector<int>> visited(n, vector<int>(n));

    queue<tuple<int, int, int, int, int>> q;
    q.emplace(sPoint.first, sPoint.second, h + 1, 0, 0);

    visited[sPoint.first][sPoint.second] = h+1;

    auto isOut = [&](int x, int y) {
        return x < 0 or x >= n or y < 0 or y >= n;
    };

    int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

    while (!q.empty()) {
        auto [x, y, hp, dur, turn] = q.front();
        q.pop();

        if (vec[x][y] == 'E') {
            cout << turn;

            return 0;
        }

        if (vec[x][y] == 'U' ) {
            dur = d;
        }

        if (dur > 0) {
            --dur;
        } else {
            --hp;
        }

        if (hp == 0) {
            continue;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];

            if (isOut(nx, ny) or visited[nx][ny] >= hp + dur) {
                continue;
            }

            visited[nx][ny] = hp + dur;

             q.emplace(nx, ny, hp, dur, turn + 1);
        }
    }

    cout << -1;

    return 0;
}