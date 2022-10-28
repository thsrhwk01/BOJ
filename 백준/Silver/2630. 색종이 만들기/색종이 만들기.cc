#include <iostream>

using namespace std;

int blue = 0, white = 0;

void cutting(int **paper, int x, int y, int size) {
    if (size == 1) { paper[x][y] == 0 ? ++white : ++blue; return; }

    const int criteria = paper[x][y];
    bool check = true;
    for (int i = x; i < x + size; ++i) {
        for (int j = y; j < y + size; ++j) {
            if (paper[i][j] != criteria) { check = false; break; }
        }
        if (!check) break;
    }

    if (check) { criteria == 0 ? ++white : ++blue; return; }

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cutting(paper, x + size / 2 * i, y + size / 2 * j, size / 2);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    int** paper;
    paper = new int* [n];

    for (int i = 0; i < n; ++i) {
        paper[i] = new int [n];
        for (int j = 0; j < n; ++j) {
            int tmp; cin >> tmp;
            paper[i][j] = tmp;
        }
    }

    cutting(paper, 0, 0, n);

    cout << white << '\n' << blue;
}