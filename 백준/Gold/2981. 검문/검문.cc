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

vi numbers, ans;

void input() {
    cin >> n;

    numbers.resize(n);

    for (auto &i : numbers)
        cin >> i;
}

void solve() {
    sort(all(numbers));

    queue<int> q;

    rep(i, 1, numbers.size() - 1) q.em(numbers[i] - numbers[i - 1]);

    int tmp = q.front();

    while (!q.empty()) {
        tmp = gcd(tmp, q.front());

        q.pop();
    }

    int limit = sqrt(tmp);
    
    rep(i, 2, limit) {
        if (tmp % i == 0) {
            ans.emb(i);

            if (tmp / i != i) ans.emb(tmp / i);
        }
    }

    ans.emb(tmp);

    sort(all(ans));
}

void output() {
    for (auto &i: ans) cout << i << ' ';
}

int main() {
    fastio;

    input();
    solve();
    output();
}