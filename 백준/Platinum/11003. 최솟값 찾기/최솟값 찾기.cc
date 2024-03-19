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
#define fastio                        \
    iostream::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

int main() {
    fastio;

    int n, l;
    cin >> n >> l;

    vi vec(n);

    for (auto &i : vec) {
        cin >> i;
    }
    
    // {value, idx}
    priority_queue<pii, vii, greater<>> pq;

    int idx = 0;

    while (idx < n) {
        pq.em(vec[idx], idx);

        while (pq.top().second <= idx - l) {
            pq.pop();
        }

        cout << pq.top().first << ' ';

        ++idx;
    }
}