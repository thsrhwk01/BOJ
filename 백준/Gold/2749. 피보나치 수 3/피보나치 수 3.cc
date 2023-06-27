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

int fibonacci[1'500'050];

ll n;

void input() { cin >> n; }

void solve() {
    fibonacci[1] = 1;
    fibonacci[2] = 1;

    rep(i, 1, 1'500'010) {
        fibonacci[i + 2] = (fibonacci[i + 1] + fibonacci[i]) % 1'000'000;
    }
}

void output() { cout << fibonacci[n % 1500000]; }

int main() {
    fastio;

    input();
    solve();
    output();
}