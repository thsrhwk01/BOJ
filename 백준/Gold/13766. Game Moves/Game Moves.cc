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

ll n, score, board[7][7], ans;

void input() {
    cin >> n;

    rep(i, 0, n - 1) {
        rep(j, 0, n - 1) { cin >> board[i][j]; }
    }

    cin >> score;
}

void solve() {
    ll tmp = 0, sum = 0, twoNumber = 0;

    rep(i, 0, n - 1) {
        rep(j, 0, n - 1) {
            if (board[i][j] >= 8) {
                ll cnt = 0, x = board[i][j];
                while (x > 1) {
                    x /= 2;
                    ++cnt;
                }
                tmp += board[i][j] * (cnt - 2);
            }

            if (board[i][j] == 2) twoNumber++;
            sum += board[i][j];
        }
    }

    twoNumber += (score - tmp) / 2;
    ll fourNumber = (sum - twoNumber * 2) / 4;

    ans = twoNumber + fourNumber - 2;
}

void output() { cout << ans << endl; }

int main() {
    fastio;

    input();
    solve();
    output();
}