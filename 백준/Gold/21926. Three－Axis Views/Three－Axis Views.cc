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

// x y z
bool isVoid[101][101][101], zy[101][101], xz[101][101], yx[101][101], ans;

int n;

void input() {
    cin >> n;

    char tmp;
    for (int z = n - 1; z >= 0; --z) {
        for (int y = 0; y < n; ++y) {
            cin >> tmp;
            zy[z][y] = '1' - tmp;

            if (zy[z][y]) {
                rep(x, 0, n - 1) { isVoid[x][y][z] = true; }
            }
        }
    }

    for (int x = n - 1; x >= 0; --x) {
        for (int z = 0; z < n; ++z) {
            cin >> tmp;
            xz[x][z] = '1' - tmp;

            if (xz[x][z]) {
                rep(y, 0, n - 1) { isVoid[x][y][z] = true; }
            }
        }
    }

    for (int y = n - 1; y >= 0; --y) {
        for (int x = 0; x < n; ++x) {
            cin >> tmp;
            yx[y][x] = '1' - tmp;

            if (yx[y][x]) {
                rep(z, 0, n - 1) { isVoid[x][y][z] = true; }
            }
        }
    }
}

void solve() {
    rep(y, 0, n - 1) {
        rep(x, 0, n - 1) {
            if (!yx[y][x]) {
                bool checker = true;

                rep(z, 0, n - 1) checker = min(checker, isVoid[x][y][z]);

                if (checker)
                    return;
            }
        }
    }

    rep(z, 0, n - 1) {
        rep(y, 0, n - 1) {
            if (!zy[z][y]) {
                bool checker = true;

                rep(x, 0, n - 1) checker = min(checker, isVoid[x][y][z]);

                if (checker)
                    return;
            }
        }
    }

    rep(x, 0, n - 1) {
        rep(z, 0, n - 1) {
            if (!xz[x][z]) {
                bool checker = true;

                rep(y, 0, n - 1) checker = min(checker, isVoid[x][y][z]);

                if (checker)
                    return;
            }
        }
    }

    ans = true;
}

void output() { cout << (ans ? "Yes" : "No"); }

int main() {
    fastio;

    input();
    solve();
    output();
}