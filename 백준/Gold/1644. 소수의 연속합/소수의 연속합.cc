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

int n, ans;

bool isPrime[4'000'001];

vi primes;

void eratosthenes() {
    memset(isPrime, true, sizeof(isPrime));

    isPrime[0] = isPrime[1] = false;

    int limit = sqrt(n);

    rep(i, 2, limit) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    rep(i, 1, n) {
        if (isPrime[i])
            primes.emb(i);
    }
}

void input() { cin >> n; }

void solve() {
    if (n == 1)
        return;

    eratosthenes();

    auto it1 = primes.begin(), it2 = primes.begin();
    int prefixSum = 0;

    while (true) {
        if (prefixSum == n) {
            ++ans;

            if (it2 == primes.end())
                return;
            prefixSum += *it2++;
        } else if (prefixSum < n) {
            if (it2 == primes.end())
                return;
            prefixSum += *it2++;
        } else {
            prefixSum -= *it1++;
        }
    }
}

void output() { cout << ans; }

int main() {
    fastio;

    input();
    solve();
    output();
}