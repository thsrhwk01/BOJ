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

bool board[102][102];

int curveNumber, curveCnts[20];

vector<vector<pii>> curves;

// right up left down
int dy[4] = {0, -1, 0, 1}, dx[4] = {1, 0, -1, 0};

inline pii turn(const pii &base, const pii &convert) {
    return {base.first + convert.second - base.second,
            base.second + base.first - convert.first};
}

void input() {
    cin >> curveNumber;

    int x, y, dir;
    curves.resize(curveNumber);
    rep(i, 0, curveNumber - 1) {
        cin >> x >> y >> dir >> curveCnts[i];

        curves[i].emb(y, x);
        curves[i].emb(y + dy[dir], x + dx[dir]);
    }
}

void curving(int idx) {
    auto &curve = curves[idx];

    for (auto &p : curve)
        board[p.first][p.second] = true;

    while (curveCnts[idx]--) {
        int endIdx = curve.size() - 1;

        for (int i = endIdx - 1; i >= 0; --i) {
            auto [y, x] = turn(curve[endIdx], curve[i]);

            board[y][x] = true;
            curve.emb(y, x);
        }
    }
}

void solve() {
    rep(i, 0, curveNumber - 1) curving(i);
}

void output() {
    int cnt = 0;

    rep(i, 0, 99)
        rep(j, 0, 99) 
            if (board[i][j] and board[i + 1][j] and
                board[i][j + 1] and board[i + 1][j + 1])
                ++cnt;
    
    cout << cnt;
}

int main() {
    fastio;

    input();
    solve();
    output();
}