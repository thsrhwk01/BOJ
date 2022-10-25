#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void checker(const vector<vector<bool>>& field, vector<vector<bool>>& checking, int x, int y);

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int cases; cin >> cases;

    while (cases--) {
        int n, m, k; cin >> n >> m >> k;
        int needs = 0;

        vector<vector<bool>> field(n, vector<bool>(m));
        vector<vector<bool>> checking(n, vector<bool>(m));
        for (auto& x : field) fill(x.begin(), x.end(), false);
        for (auto& x : checking) fill(x.begin(), x.end(), false);

        while(k--) {
            int x, y; cin >> x >> y;
            field[x][y] = true;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!field[i][j] || checking[i][j]) continue;
                ++needs;
                checker(field, checking, i, j);
            }
        }

        cout << needs << '\n';
    }
}

void checker(const vector<vector<bool>>& field, vector<vector<bool>>& checking, int x, int y) {
    if (x < 0 ||
    x >= field.size() ||
    y < 0 ||
    y >= field[0].size() ||
    !field[x][y] || checking[x][y]) return;
    checking[x][y] = true;

    checker(field, checking, x - 1, y);
    checker(field, checking, x + 1, y);
    checker(field, checking, x, y -1);
    checker(field, checking, x, y + 1);
}