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

ll n, m;
set<ll> ls;

void calculate(ll x) {
    if (ls.find(x) != ls.end())
        return;
    if (x < m)
        return;

    ls.em(x);

    calculate(x / 2);
    if (x & 1) {
        calculate(x / 2 + 1);
    }
}

int main() {
    fastio;

    cin >> n >> m;

    if (m == n) {
        cout << "YES";
        return 0;
    }

    calculate(n);

    cout << (ls.find(m) != ls.end() ? "YES" : "NO");
}