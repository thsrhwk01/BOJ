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

int n;
bool results[1'000'002];

void solve() {
    rep(i, 1, 1'000'000) {
        [&]() {
            for (int j = sqrt(i); j > 0; --j) {
                if (!results[i - j * j]) {
                    results[i] = true;
                    return;
                }
            }

            results[i] = false;
        }();
    }
}

void input() { cin >> n; }

void output() { cout << (results[n] ? "koosaga" : "cubelover") << endl; }

int main() {
    fastio;
    results[0] = false;

    solve();

    int t;
    cin >> t;

    while (t--) {
        input();
        output();
    }
}