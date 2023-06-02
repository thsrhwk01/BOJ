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

int n, q;

// Segment Tree
const int MAX_N = 100'005;
ll min_seg[4 * MAX_N], max_seg[4 * MAX_N], arr[MAX_N];

// Build Minimum Segment Tree
ll min_init (int node, int start, int end) {
    if (start == end) return min_seg[node] = arr[start];

    int mid = (start + end) / 2;
    return min_seg[node] = min(min_init(node * 2, start, mid), min_init(node * 2 + 1, mid + 1, end));
}

// Build Maximum Segment Tree
ll max_init (int node, int start, int end) {
    if (start == end) return max_seg[node] = arr[start];

    int mid = (start + end) / 2;
    return max_seg[node] = max(max_init(node * 2, start, mid), max_init(node * 2 + 1, mid + 1, end));
}

// Query Segment Tree
// left, right: Query Range
ll min_query (int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0x7f7f7f7f;

    if (left <= start && end <= right) return min_seg[node];

    int mid = (start + end) / 2;
    return min(min_query(node * 2, start, mid, left, right), min_query(node * 2 + 1, mid + 1, end, left, right));
}


// Query Segment Tree
// left, right: Query Range
ll max_query (int node, int start, int end, int left, int right) {
    if (left > end || right < start) return -1;

    if (left <= start && end <= right) return max_seg[node];

    int mid = (start + end) / 2;
    return max(max_query(node * 2, start, mid, left, right), max_query(node * 2 + 1, mid + 1, end, left, right));
}

void input() {
    cin >> n >> q;

    // Array's start index is 1.
    rep(i, 1, n) cin >> arr[i];

    // Segment Tree's start index is 1.
    min_init(1, 1, n);
    max_init(1, 1, n);
}

void solve() {
    while (q--) {
        int a, b;
        cin >> a >> b;

        cout << min_query(1, 1, n, a, b) << ' ' << max_query(1, 1, n, a, b) << endl;
    }
}


int main() {
    fastio;

    input();
    solve();
}