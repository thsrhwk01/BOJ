#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define endl '\n'

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int r, c;
    cin >> r >> c;

    vector<string> boardOri(r);

    for (int i = 0; i < r; ++i) {
        cin >> boardOri[i];
    }
    auto boardAft = boardOri;

    auto isOut = [&](int x, int y) {
        return x < 0 or x >= r or y < 0 or y >= c;
    };

    for (int x = 0; x < r; ++x) {
        for (int y = 0; y < c; ++y) {
            int cnt = 0;

            for (int k = 0; k < 4; ++k) {
                int nx = dx[k] + x, ny = dy[k] + y;

                if (isOut(nx, ny) or boardOri[nx][ny] == '.') {
                    ++cnt;
                }
            }

            if (cnt > 2) {
                boardAft[x][y] = '.';
            }
        }
    }

    int rb, re, cb, ce;

    for (int i = 0; i < r; i++) {
        bool isLand = false;

        for (int j = 0; j < c; j++) {
            if (boardAft[i][j] == 'X') {
                isLand = true;
            }
        }

        if (isLand) {
            rb = i;

            break;
        }
    }

    for (int i = r - 1; i > 0; i--) {
        bool isLand = false;

        for (int j = 0; j < c; j++) {
            if (boardAft[i][j] == 'X') {
                isLand = true;
            }
        }

        if (isLand) {
            re = i;

            break;
        }
    }

    for (int i = 0; i < c; i++) {
        bool isLand = false;

        for (int j = 0; j < r; j++) {
            if (boardAft[j][i] == 'X') {
                isLand = true;
            }
        }

        if (isLand) {
            cb = i;

            break;
        }
    }

    for (int i = c - 1; i > 0; i--) {
        bool isLand = false;

        for (int j = 0; j < r; j++) {
            if (boardAft[j][i] == 'X') {
                isLand = true;
            }
        }

        if (isLand) {
            ce = i;

            break;
        }
    }

    for (int i = rb; i <= re; i++) {
        for (int j = cb; j <= ce; j++) {
            cout << boardAft[i][j];
        }

        cout << endl;
    }

    return 0;
}