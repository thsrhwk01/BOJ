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

int a, b, c;

void input() { cin >> a >> b >> c; }

void solve() {}

void output() {
    cout << (a + b) % c << endl
         << ((a % c) + (b % c)) % c << endl
         << (a * b) % c << endl
         << ((a % c) * (b % c)) % c;
}

int main() {
    fastio;

    input();
    solve();
    output();
}