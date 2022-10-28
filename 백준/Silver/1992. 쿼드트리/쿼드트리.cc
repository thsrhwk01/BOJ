#include <iostream>

using namespace std;

string ans;

void solve(int** movie, int x, int y, int size) {
    if (size == 1) { ans += to_string(movie[x][y]); return; }

    auto criteria = movie[x][y];
    bool check = true;
    for (int i = x; i < x + size; ++i) {
        for (int j = y; j < y + size; ++j) {
            if (movie[i][j] != criteria) { check = false; break; }
        }
    }

    if (check) ans += to_string(criteria);
    else {
        ans += '(';
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                solve(movie, x + size / 2 * i, y + size / 2 * j, size / 2);
            }
        }
        ans += ')';
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    int** movie;
    movie = new int *[n];

    for (int i = 0; i < n; ++i) {
        movie[i] = new int [n];
        string tmp; cin >> tmp;
        for (int j = 0; j < n; ++j) {
            movie[i][j] = tmp[j] - 48;
        }
    }
    solve(movie, 0, 0, n);

    cout << ans;
}