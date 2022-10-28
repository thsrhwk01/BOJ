#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<int, int> cnt;

void cutting(const vector<vector<int>>& matrix, int x, int y, int size) {
    if (size == 1) { ++cnt[matrix[x][y]]; return; }

    int criteria = matrix[x][y];
    bool check = true;
    for (int i = x; i < x + size; ++i) {
        for (int j = y; j < y + size; ++j)
            if (matrix[i][j] != criteria) {
                check = false;
                break;
            }
        if (!check) break;
    }
    if (check) {
        ++cnt[criteria];
    }

    else {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j)
                cutting(matrix, x + size / 3 * i, y + size / 3 * j, size / 3);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cnt[-1] = 0; cnt[0] = 0; cnt[1] = 0;
    int n; cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));

    for (auto& x : matrix)
        for (auto& y : x) cin >> y;

    cutting(matrix, 0, 0, n);

    cout << cnt[-1] << '\n' << cnt[0] << '\n' << cnt[1];
}