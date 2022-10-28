#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int ans = 0;

void ripening(int** tomato, const vector<pair<int, int>>& start_positions, pair<int, int> size) {
    queue<pair<pair<int, int>, int>> q;
    // {{x, y}, time}
    for (const auto& pos : start_positions)
        q.emplace(make_pair(pos.first, pos.second), 0);

    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int time = q.front().second;
        q.pop();

        ans = max(ans, time);

        if (x-1 >= 0 && tomato[x-1][y] == -1) {
            tomato[x-1][y] = time + 1;
            q.emplace(make_pair(x-1, y), time + 1);
        }
        if (y-1 >= 0 && tomato[x][y-1] == -1) {
            tomato[x][y-1] = time + 1;
            q.emplace(make_pair(x, y-1), time + 1);
        }
        if (x+1 < size.first && tomato[x+1][y] == -1) {
            tomato[x+1][y] = time + 1;
            q.emplace(make_pair(x+1, y), time + 1);
        }
        if (y+1 < size.second && tomato[x][y+1] == -1) {
            tomato[x][y+1] = time + 1;
            q.emplace(make_pair(x, y+1), time + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n, m; cin >> n >> m;

    int** tomato = new int* [m];
    // 토마토 유무와 익었는지 저장, 후에는 익은 시간 저장

    vector<pair<int, int>> start_positions;

    for (int i = 0; i < m; ++i) {
        tomato[i] = new int [n];
        for (int j = 0; j < n; ++j) {
            cin >> tomato[i][j];
            /*
             * tomato == -2 : 토마 토 X
             * tomato == -1 : 안 익음
             * tomato ==  0 : 익음
             */

            if (--tomato[i][j] == 0) start_positions.emplace_back(i, j);
        }
    }

    if (start_positions.empty()) { cout << -1; return 0; }
    //익은 것이 한 개도 없으면 -1 출력 후 종료

    ripening(tomato, start_positions, {m, n});
    //bfs

    bool check = true;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (tomato[i][j] == -1) {
                check = false;
                break;
            }
        }
        if (!check) break;
    }

    if (check) cout << ans;
    else cout << -1;
}