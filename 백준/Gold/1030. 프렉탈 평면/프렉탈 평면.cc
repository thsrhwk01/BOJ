#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

using ll = long long;

ll board[8][8];

string ans;

ll S, N, K, row1, row2, col1, col2;

void input() { cin >> S >> N >> K >> row1 >> row2 >> col1 >> col2; }

ll getColor(ll x, ll y, ll nowSecond) {
    //cout << x << ' ' << y << ' ' << endl;
    if (nowSecond == 0)
        return 0;

    ll temp_x = x % N, temp_y = y % N;
    //cout << temp_x << ' ' << temp_y << ' ' << endl;
    if (board[temp_y][temp_x] == 1)
        return 1;

    else
        return getColor(x / N, y / N, nowSecond - 1);
}

void solve() {
    for (ll i = N / 2 - K / 2; i < N / 2 + K / 2 + (N % 2); ++i)
        for (ll j = N / 2 - K / 2; j < N / 2 + K / 2 + (N % 2); ++j)
            board[i][j] = 1;

    for (ll y = row1; y <= row2; ++y) {
        for (ll x = col1; x <= col2; ++x) {
            cout << getColor(x, y, S);
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();
}