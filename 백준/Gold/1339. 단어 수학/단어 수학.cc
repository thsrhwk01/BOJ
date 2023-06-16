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

map<char, ll> mp;

ll ans;

void input() {
    int n;
    cin >> n;

    string num;

    while (n--) {
        cin >> num;

        reverse(all(num));

        int i = 1;

        for (auto &c : num) {
            mp[c] += i;

            i *= 10;
        }
    }
}

void solve() {
    vector<ll> vec;

    for (auto &p : mp)
        vec.emb(p.second);

    sort(all(vec), greater<>());

    int i = 9;

    for (auto &x : vec) {
        ans += x * i;
        --i;
    }
}

void output() { cout << ans; }

int main() {
    fastio;

    input();
    solve();
    output();
}