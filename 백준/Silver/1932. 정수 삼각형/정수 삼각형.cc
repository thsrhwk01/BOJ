#include <iostream>
#include <algorithm>

//#define debug

using namespace std;

int **triangle;
int *tmp1, *tmp2;

int height;

void input() {
    cin >> height;

    triangle = new int *[height];
    tmp1 = new int[height];
    tmp2 = new int[height];

    for (int i = 0; i < height; ++i) {
        triangle[i] = new int[height];
        for (int j = 0; j <= i; ++j) {
            cin >> triangle[i][j];
        }
    }
}

void solve() {
    tmp1[0] = triangle[0][0];
    for (int i = 1; i < height; ++i) {
        tmp2[0] = tmp1[0] + triangle[i][0];
        tmp2[i] = tmp1[i-1] + triangle[i][i];

        for (int j = 1; j < i; ++j) {
            tmp2[j] = max(triangle[i][j] + tmp1[j-1], triangle[i][j] + tmp1[j]);
        }

        swap(tmp1, tmp2);
    }
}

void output() {
#ifdef debug
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << triangle[i][j] << ' ';
        }
        cout << endl;
    }
#endif
    cout << *max_element(tmp1, tmp1 + height);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    solve();
    output();
}