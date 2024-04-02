#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using tiii = tuple<int, int, int>;
using viii = vector<tiii>;

#define endl '\n'
#define em emplace
#define emb emplace_back
#define all(x) x.begin(), x.end()
#define rep(i, from, to) for (int i = from; i <= to; ++i)

void solve() {
    int h, w, ans = 0;
    cin >> h >> w;

    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    auto isOut = [&](int y, int x) {
        return (x < 0 or x >= w or y < 0 or y >= h);
    };

    vector<string> board(h);
    vector<vector<bool>> isVisited(h, vector<bool>(w));

    for (auto &row : board) {
        cin >> row;
    }

    for (auto &row : isVisited) {
        fill(all(row), false);
    }

    string k;
    vi keys;
    cin >> k;
    if (k != "0") {
        for (auto c : k) {
            keys.emb(c - 'a');
        }
    }

    // {y, x}
    vector<pii> reservedList[26];
    queue<pii> q;

    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            if (y != 0 and y != h - 1 and x != 0 and x != w - 1) {
                continue;
            }

            auto block = board[y][x];

            if (block == '*') {
                continue;
            } else if (block >= 'A' and block <= 'Z' and
                       find(all(keys), block - 'A') == keys.end()) {
                isVisited[y][x] = true;
                reservedList[block - 'A'].emb(y, x);
            } else {
                isVisited[y][x] = true;
                q.em(y, x);
            }
        }
    }

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();
        
        auto block = board[y][x];

        if (block == '$') {
            ++ans;
        } else if (block >= 'a' and block <= 'z') {
            keys.emb(block - 'a');
            for (auto reserved : reservedList[block - 'a']) {
                q.em(reserved);
            }
        }

        for (auto dir : dirs) {
            int ny = y + dir[0], nx = x + dir[1];

            if (isOut(ny, nx) or isVisited[ny][nx]) {
                continue;
            }

            auto nBlock = board[ny][nx];

            if (nBlock == '*') {
                continue;
            } else if (nBlock >= 'A' and nBlock <= 'Z' and
                       find(all(keys), nBlock - 'A') == keys.end()) {
                isVisited[ny][nx] = true;
                reservedList[nBlock - 'A'].emb(ny, nx);
            } else {
                isVisited[ny][nx] = true;
                q.em(ny, nx);
            }
        }
    }

    cout << ans << endl;
}

int main() {
    iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}