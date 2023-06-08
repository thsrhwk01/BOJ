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

priority_queue<int, vi, greater<>> pq;

ll ans;

void input() {
    int n;
    cin >> n;

    int tmp;
    while (n--) {
        cin >> tmp;
        pq.em(tmp);
    }
}

void solve() {
    while (pq.size() >= 2) {
        int fir = pq.top();
        pq.pop();
        int sec = pq.top();
        pq.pop();

        int cnt = fir + sec;
        ans += cnt;

        pq.em(cnt);
    }
}

void output() { cout << ans; }

int main() {
    fastio;

    input();
    solve();
    output();
}