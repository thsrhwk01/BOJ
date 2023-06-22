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


ll ans;

priority_queue<ll> positiveQ;
priority_queue<ll, vector<ll>, greater<>> negativeQ;

void input() {
    int n;
    cin >> n;

    ll tmp;

    while (n--) {
        cin >> tmp;

        if (tmp <= 0)
            negativeQ.em(tmp);
        else if (tmp > 1)
            positiveQ.em(tmp);
        else
            ans += tmp;
    }
}

void solve() {
    while (positiveQ.size() >= 2) {
        ll a = positiveQ.top();
        positiveQ.pop();

        ll b = positiveQ.top();
        positiveQ.pop();

        ans += a * b;
    }

    if (!positiveQ.empty())
        ans += positiveQ.top();

    while (negativeQ.size() >= 2) {
        ll a = negativeQ.top();
        negativeQ.pop();

        ll b = negativeQ.top();
        negativeQ.pop();

        ans += a * b;
    }

    if (!negativeQ.empty())
        ans += negativeQ.top();
}

void output() { cout << ans; }

int main() {
    fastio;

    input();
    solve();
    output();
}