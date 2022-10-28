#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

int ans = 0;

void ripening(int*** tomato, const vector<tuple<int, int, int>>& start_positions, tuple<int, int, int> size) {
    queue<pair<tuple<int, int, int>, int>> q;
    // {{x, y}, time}
    for (const auto& pos : start_positions)
        q.emplace(make_tuple(get<0>(pos), get<1>(pos), get<2>(pos)), 0);

    while (!q.empty()) {
        int x = get<1>(q.front().first);
        int y = get<2>(q.front().first);
        int z = get<0>(q.front().first);
        int time = q.front().second;
        q.pop();

        ans = max(ans, time);

        if (x-1 >= 0 && tomato[z][x-1][y] == -1) {
            tomato[z][x-1][y] = time + 1;
            q.emplace(make_tuple(z, x-1, y), time + 1);
        }
        if (y-1 >= 0 && tomato[z][x][y-1] == -1) {
            tomato[z][x][y-1] = time + 1;
            q.emplace(make_tuple(z, x, y-1), time + 1);
        }
        if (z-1 >= 0 && tomato[z-1][x][y] == -1) {
            tomato[z-1][x][y] = time + 1;
            q.emplace(make_tuple(z-1, x, y), time + 1);
        }
        if (x+1 < get<1>(size) && tomato[z][x+1][y] == -1) {
            tomato[z][x+1][y] = time + 1;
            q.emplace(make_tuple(z, x+1, y), time + 1);
        }
        if (y+1 < get<2>(size) && tomato[z][x][y+1] == -1) {
            tomato[z][x][y+1] = time + 1;
            q.emplace(make_tuple(z, x, y+1), time + 1);
        }
        if (z+1 < get<0>(size) && tomato[z+1][x][y] == -1) {
            tomato[z+1][x][y] = time + 1;
            q.emplace(make_tuple(z+1, x, y), time + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n, m, h; cin >> n >> m >> h;

    int*** tomato = new int** [h];
    // 토마토 유무와 익었는지 저장, 후에는 익은 시간 저장

    vector<tuple<int, int, int>> start_positions;
    // z, y, x 순

    for (int i = 0; i < h; ++i) {
        tomato[i] = new int* [m];
        for (int j = 0; j < m; ++j) {
            tomato[i][j] = new int [n];
            for (int k = 0; k < n; ++k) {
                cin >> tomato[i][j][k];
                /*
                 * tomato == -2 : 토마 토 X
                 * tomato == -1 : 안 익음
                 * tomato ==  0 : 익음
                 */

                if (--tomato[i][j][k] == 0) start_positions.emplace_back(i, j, k);
            }
        }
    }

    if (start_positions.empty()) { cout << -1; return 0; }
    //익은 것이 한 개도 없으면 -1 출력 후 종료

    ripening(tomato, start_positions, {h, m, n});
    //bfs

    bool check = true;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < n; ++k) {
                if (tomato[i][j][k] == -1) {
                    check = false;
                    break;
                }
            }
        }
        if (!check) break;
    }

    if (check) cout << ans;
    else cout << -1;
}

