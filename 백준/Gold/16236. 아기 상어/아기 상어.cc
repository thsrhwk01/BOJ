#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct pd {
    int x, y, dist;

    pd(int x, int y, int dist) : x(x), y(y), dist(dist) {};
};

int level = 2, exp = 0;
int bx, by;
int sec = 0;

pd select_bps (const vector<pd>&);
void solve(vector<vector<int>>&, size_t);

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n; cin >> n;
    vector<vector<int>> vec(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> vec[i][j];
            if (vec[i][j] == 9) {
                bx = i;
                by = j;
                vec[i][j] = 0;
            }
        }
    }

    solve(vec, n);

    cout << sec;
}

pd select_bps (const vector<pd>& bps) {
    int x = 0;
    for (int i = 0; i < bps.size(); ++i) {
        if ((bps[i].x < bps[x].x) || (bps[i].x == bps[x].x && bps[i].y < bps[x].y)) x = i;
    }

    return bps[x];
}

void solve(vector<vector<int>>& vec, size_t border) {
    vector<vector<bool>> visited(border, vector<bool>(border));

    while (true) {
        vector<pd> bps;

        queue<pd> q;
        q.emplace(bx, by, 0);

        int nx, ny, ndist;

        for (auto& asdf : visited) {
            fill(asdf.begin(), asdf.end(), false);
        }

        visited[bx][by] = true;
        while (!q.empty()) {
            nx = q.front().x;
            ny = q.front().y;
            ndist = q.front().dist;

            q.pop();

            if(!bps.empty() && ndist >= bps.begin()->dist) continue;

            if (nx > 0 && !visited[nx-1][ny] && vec[nx-1][ny] <= level) {
                if (bps.empty()) {
                    if (vec[nx-1][ny] == 0 || vec[nx-1][ny] == level)
                        q.emplace(nx-1, ny, ndist+1);
                    else
                        bps.emplace_back(nx-1, ny, ndist+1);
                }
                else if (vec[nx-1][ny] != 0 && vec[nx-1][ny] != level)
                    bps.emplace_back(nx-1, ny, ndist+1);

                visited[nx-1][ny] = true;
            }
            if (ny > 0 && !visited[nx][ny-1] && vec[nx][ny-1] <= level) {
                if (bps.empty()) {
                    if (vec[nx][ny-1] == 0 || vec[nx][ny-1] == level)
                        q.emplace(nx, ny-1, ndist+1);
                    else
                        bps.emplace_back(nx, ny-1, ndist+1);
                }
                else if (vec[nx][ny-1] != 0 && vec[nx][ny-1] != level)
                    bps.emplace_back(nx, ny-1, ndist+1);

                visited[nx][ny-1] = true;
            }
            if (nx + 1 < border && !visited[nx+1][ny] && vec[nx+1][ny] <= level) {
                if (bps.empty()) {
                    if (vec[nx+1][ny] == 0 || vec[nx+1][ny] == level)
                        q.emplace(nx+1, ny, ndist+1);
                    else
                        bps.emplace_back(nx+1, ny, ndist+1);
                }
                else if (vec[nx+1][ny] != 0 && vec[nx+1][ny] != level)
                    bps.emplace_back(nx+1, ny, ndist+1);

                visited[nx+1][ny] = true;
            }
            if (ny + 1 < border && !visited[nx][ny+1] && vec[nx][ny+1] <= level) {
                if (bps.empty()) {
                    if (vec[nx][ny+1] == 0 || vec[nx][ny+1] == level)
                        q.emplace(nx, ny+1, ndist+1);
                    else
                        bps.emplace_back(nx, ny+1, ndist+1);
                }
                else if (vec[nx][ny+1] != 0 && vec[nx][ny+1] != level)
                    bps.emplace_back(nx, ny+1, ndist+1);

                visited[nx][ny+1] = true;
            }
        }
        if (bps.empty()) break;

        auto next = select_bps(bps);

        vec[next.x][next.y] = 0;
        ++exp; if (level == exp) { ++level; exp = 0; }
        bx = next.x; by = next.y;

        sec += next.dist;
    }
}