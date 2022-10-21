//
// Created by woo-young Choi on 2022/10/12.
//

#include <bits/stdc++.h>

#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

char board[3072][6144];
int n;

void starlight(int x, int y) {
    board[y][x] = '*';
    board[y+1][x-1] = '*';
    board[y+1][x + 1] = '*';
    fill_n(board[y+2] + x - 2, 5, '*');
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
}

void solve() {
    for (int i = 0; i < n; ++i) {
        fill_n(board[i], n * 2, ' ');
    }
    triple(n, n - 1, 0);
}

void output() {
    ostream_iterator<char> os(cout, "");
    for (int i = 0; i < n; ++i) {
        copy_n(board[i], n * 2, os);
        cout << endl;
    }
}

int main() {
    fastio

    input();
    solve();
    output();
}
