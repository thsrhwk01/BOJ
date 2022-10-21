//
// Created by woo-young Choi on 2022/10/12.
//

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

array<string, 3072> board;
int n, cnt;

void starlight(int x, int y) {
    board[y][x] = '*';
    --x;
    ++y;
    board[y][x] = '*';
    board[y][x + 2] = '*';
    --x;
    ++y;
    for (int i = x; i < x + 5; ++i) {
        board[y][i] = '*';
    }
}

void triple(int len, int x, int y) {
    if (len == 3) {
        starlight(x, y);

        return;
    }

    triple(len / 2, x, y);
    triple(len / 2, x - len / 2, y + len / 2);
    triple(len / 2, x + len / 2, y + len / 2);
}

void input() {
    cin >> n;
    cnt = n / 3;
}

void solve() {
    for (auto &str: board) {
        str.resize(6145);
        fill_n(str.begin(), 6144, ' ');
    }
    triple(n, n - 1, 0);
}

void output() {
    ostream_iterator<char> os(cout, "");
    for (int i = 0; i < n; ++i) {
        copy_n(board[i].begin(), n * 2, os);
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    solve();
    output();
}
