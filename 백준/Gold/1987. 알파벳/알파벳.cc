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

int n, m, ans;

string board[20];

// up down left right
pii dirs[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isVisited[26];

void input() {
    cin >> n >> m;

    rep(i, 0, n - 1) cin >> board[i];
}

inline bool isOut(int y, int x) { return (y < 0 || y >= n || x < 0 || x >= m); }

void dfs(int y, int x, int cnt) {
    char nowChar = board[y][x];

    if (isVisited[nowChar - 'A']) {
        ans = max(ans, cnt);
        return;
    }

    isVisited[nowChar - 'A'] = true;

    rep(i, 0, 3) {
        int ny = y + dirs[i].first, nx = x + dirs[i].second;

        if (isOut(ny, nx))
            continue;

        dfs(ny, nx, cnt + 1);
    }

    isVisited[nowChar - 'A'] = false;
}

void solve() { dfs(0, 0, 0); }

void output() { cout << ans; }

int main() {
    fastio;

    input();
    solve();
    output();
}