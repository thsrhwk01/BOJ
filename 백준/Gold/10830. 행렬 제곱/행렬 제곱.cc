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

array<array<int, 5>, 5> mat, ans, matEmpty;

ll n, b;

array<array<int, 5>, 5> mul(const array<array<int, 5>, 5> &lhs,
                            const array<array<int, 5>, 5> &rhs) {
    auto ret = matEmpty;

    rep(i, 0, n - 1) {
        rep(j, 0, n - 1) {
            rep(k, 0, n - 1) { ret[i][j] += lhs[i][k] * rhs[k][j]; }

            ret[i][j] %= 1000;
        }
    }

    return ret;
}

void input() {
    cin >> n >> b;

    rep(i, 0, n - 1) {
        rep(j, 0, n - 1) { cin >> mat[i][j]; }
    }
}

void solve() {
    rep(i, 0, 4) ans[i][i] = 1;

    vi exponentArr;

    while (b > 0) {
        exponentArr.emb(b);
        b /= 2;
    }

    reverse(all(exponentArr));

    for (auto &i: exponentArr) {
        ans = mul(ans, ans);

        if (i & 1)
            ans = mul(ans, mat);
    }
}

void output() {
    rep(i, 0, n - 1) {
        rep(j, 0, n - 1) { cout << ans[i][j] << ' '; }
        cout << endl;
    }
}

int main() {
    fastio;

    input();
    solve();
    output();
}