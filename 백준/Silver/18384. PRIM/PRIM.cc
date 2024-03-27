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

set<int> eratosthenes;

void eratos() {
    vector<bool> isPrime(100'100);
    fill(all(isPrime), 1);

    for (int i = 2; i < 100'100; ++i) {
        if (!isPrime[i]) continue;

        eratosthenes.em(i);

        int j = i * 2;
        while (j < 100'100) {
            isPrime[j] = false;
            j += i;
        }
    }
}

void solve() {
    int ans = 0;

    for (int i = 0; i < 5; ++i) {
        int x;
        cin >> x;

        auto it = eratosthenes.lower_bound(x);
        ans += *it;
    }

    cout << ans << endl;
}

int main() {
    iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    eratos();

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}