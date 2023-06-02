#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

#define endl '\n'
#define em emplace
#define emb emplace_back
#define all(x) x.begin(), x.end()
#define rep(i, from, to) for (int i = from; i <= to; ++i)
#define fastio                                                                 \
    iostream::sync_with_stdio(false);                                          \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);

bool board[2'200][2'200];

int n;

void input() { cin >> n; }

void divideConquer(int y, int x, int length) {
    if (length == 1) {
        board[y][x] = true;
        return;
    }

    int nextLength = length / 3;

    rep(i, 0, 2) {
        rep(j, 0, 2) {
            if (i == 1 && j == 1)
                continue;

            divideConquer(y + i * nextLength, x + j * nextLength, nextLength);
        }
    }
}

void solve() { divideConquer(1, 1, n); }

void output() {
    rep(i, 1, n) {
        rep(j, 1, n) cout << (board[i][j] ? '*' : ' ');
        cout << endl;
    }
}

int main() {
    fastio;

    input();
    solve();
    output();
}