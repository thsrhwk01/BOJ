//
// Created by woo-young Choi on 2022/10/12.
//

#include <bits/stdc++.h>

#define pii pair<int, int>
#define endl '\n'

using namespace std;

vector<vector<int>> board, visited;

queue<pair<int, int>> now, reserved, airfilling;

int n, m, sec = 0;

int range[3] = {-1, 0, 1};

int counter(int x, int y) {
    if (visited[x][y]) return 0;
    int tmp = 0;

    for (int dx: range) {
        for (int dy: range) {
            if (dx != 0 && dy != 0) continue;
            if (dx == 0 && dy == 0) continue;

            int tmpx = x + dx, tmpy = y + dy;

            if (tmpx >= 0 && tmpx < n && tmpy >= 0 && tmpy < m && board[tmpx][tmpy] == 0) ++tmp;
        }
    }

    return tmp;
}

void emplacer(queue<pair<int, int>> &q, int x, int y) {
    visited[x][y] = true;
    q.emplace(x, y);
}

void airing() {
    while (!airfilling.empty()) {
        int x = airfilling.front().first, y = airfilling.front().second;

        board[x][y] = 0;
        airfilling.pop();

        for (int dx: range) {
            for (int dy: range) {
                if (dx != 0 && dy != 0) continue;
                if (dx == 0 && dy == 0) continue;

                int tmpx = x + dx, tmpy = y + dy;

                if ((tmpx >= 0 && tmpx < n) && (tmpy >= 0 && tmpy < m)) {
                    switch (board[tmpx][tmpy]) {
                        case 1:
                            if(counter(tmpx, tmpy) > 1) emplacer(reserved, tmpx, tmpy);
                            break;
                        case -1:
                            if (!visited[tmpx][tmpy]) emplacer(airfilling, tmpx, tmpy);
                            break;
                    }
                }
            }
        }
    }
}

void print_board() {
    ostream_iterator<int> os(cout, "\t");
    for (const auto &row: board) {
        copy(row.begin(), row.end(), os);
        cout << endl;
    }
}

void input() {
    cin >> n >> m;
    board.resize(n);

    for (auto &row: board) {
        row.resize(m);
        for (auto &block: row) {
            cin >> block;
            if (block == 0) block = -1;
        }
    }
}

void solve() {
    visited.resize(n);

    for (auto &row: visited) {
        row.resize(m);
        fill(row.begin(), row.end(), false);
    }

    for (int i = 0; i < m; ++i) {
        board[0][i] = 0;
        board[n - 1][i] = 0;
        airfilling.emplace(0, i);
        airfilling.emplace(n - 1, i);
    }
    for (int i = 0; i < n; ++i) {
        board[i][0] = 0;
        board[i][m - 1] = 0;
        airfilling.emplace(i, 0);
        airfilling.emplace(i, m - 1);
    }

    airing();
    swap(now, reserved);

    while (!now.empty()) {
        int x = now.front().first, y = now.front().second;
        now.pop();

        board[x][y] = 0;

        for (int dx: range) {
            for (int dy: range) {
                if (dx != 0 && dy != 0) continue;
                if (dx == 0 && dy == 0) continue;

                int tmpx = x + dx, tmpy = y + dy;

                if ((tmpx >= 0 && tmpx < n) && (tmpy >= 0 && tmpy < m)) {
                    switch (board[tmpx][tmpy]) {
                        case 1:
                            if(counter(tmpx, tmpy) > 1) emplacer(reserved, tmpx, tmpy);
                            break;
                        case -1:
                            if (!visited[tmpx][tmpy]) emplacer(airfilling, tmpx, tmpy);
                            break;
                    }
                }
            }
        }

        if (now.empty()) {
            airing();
            swap(now, reserved);
            ++sec;
        }
    }
}

void output() {
    cout << sec;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    solve();
    output();
}
