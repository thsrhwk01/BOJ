#include <bits/stdc++.h>

using namespace std;

using ll  = long long;
using vi  = vector<int>;
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
    cout.tie(nullptr);                                                         \

// Segment Tree
vector<ll> seg, arr;

// Build Segment Tree
ll init (int node, int start, int end) {
    if (start == end) return seg[node] = arr[start];

    int mid = (start + end) / 2;
    return seg[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

// Update Segment Tree
// idx: Update Target Node, val: Update Value
ll update (int node, int start, int end, int idx, ll val) {
    if (idx < start || idx > end) return seg[node];

    if (start == end) return seg[node] = val;

    int mid = (start + end) / 2;
    return seg[node] = update(node * 2, start, mid, idx, val) + update(node * 2 + 1, mid + 1, end, idx, val);
}

// Query Segment Tree
// left, right: Query Range
ll query (int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;

    if (left <= start && end <= right) return seg[node];

    int mid = (start + end) / 2;
    return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
    fastio;

    int n, m, k;

    cin >> n >> m >> k;
    arr.resize(n + 1);
    rep(i, 1, n) cin >> arr[i];

    seg.resize(4 * n);
    init(1, 1, n);

    m += k;

    ll command, a, b;
    while (m--) {
        cin >> command >> a >> b;

        switch (command)
        {
        case 1:
            update(1, 1, n, a, b);
            break;
        
        case 2:
            cout << query(1, 1, n, a, b) << endl;
            break;
        }
    }
}