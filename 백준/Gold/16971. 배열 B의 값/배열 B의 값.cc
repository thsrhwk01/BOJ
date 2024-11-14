#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> vec(n, vector<int>(m));

    vector<long long> rows(n), cols(m);

    long long ans = 0;

    for (auto &&row : vec) {
        for (auto &&cell : row) {
            cin >> cell;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            rows[i] += vec[i][j] * (j == 0 or j == m - 1 ? 1 : 2);
        }
    }

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            cols[j] += vec[i][j] * (i == 0 or i == n - 1 ? 1 : 2);
        }
    }

    long long minIdx = 1, minValue = rows[1];
    for (int i = 1; i < n - 1; i++) {
        if (minValue > rows[i]) {
            minIdx = i;
            minValue = rows[i];
        }
    }
    long long maxIdx = rows[0] > rows[n - 1] ? 0 : n - 1;

    if (rows[maxIdx] > rows[minIdx]) {
        swap(rows[minIdx], rows[maxIdx]);
    }

    long long ans1 = 0;
    for (auto &&row : rows) {
        ans1 += row * 2;
    }
    ans1 -= rows[0] + rows[n - 1];

    minIdx = 1, minValue = cols[1];
    for (int i = 1; i < m - 1; i++) {
        if (minValue > cols[i]) {
            minIdx = i;
            minValue = cols[i];
        }
    }
    maxIdx = cols[0] > cols[m - 1] ? 0 : m - 1;

    if (cols[maxIdx] > cols[minIdx]) {
        swap(cols[maxIdx], cols[minIdx]);
    }

    long long ans2 = 0;
    for (auto &&col : cols) {
        ans2 += col * 2;
    }
    ans2 -= cols[0] + cols[m - 1];

    cout << max(ans1, ans2);
}