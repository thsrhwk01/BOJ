#include <functional>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n));

    for (auto &&row : board) {
        for (auto &&cell : row) {
            cin >> cell;
        }
    }

    priority_queue<tuple<long long, int, int>,
                   vector<tuple<long long, int, int>>, greater<>>
        pq;

    vector<vector<bool>> isVisited(n, vector<bool>(n));

    pq.emplace(0, 0, 0);

    int dx[] = {0, 1};
    int dy[] = {1, 0};

    while (!pq.empty()) {
        auto [cost, x, y] = pq.top();
        pq.pop();

        if (isVisited[x][y]) {
            continue;
        }
        isVisited[x][y] = true;

        if (x == n - 1 and y == n - 1) {
            cout << cost;

            break;
        }

        int weight = board[x][y];

        for (int i = 0; i < 2; i++) {
            int nx = x + dx[i], ny = y + dy[i];

            if (nx >= n or ny >= n) {
                continue;
            }

            int nWeight = board[nx][ny];
            
            pq.emplace(cost + (weight > nWeight ? 0 : nWeight - weight + 1), nx, ny);
        }
    }

    return 0;
}