#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

#define endl '\n'

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> vec(n);
    struct pair_hash {
        inline auto operator()(const pair<int, int> &p) const {
            return p.first * 10'007 + p.second;
        }
    };

    unordered_set<pair<int, int>, pair_hash> us;

    for (auto &&[x, y] : vec) {
        cin >> x >> y;
        us.emplace(x, y);
    }

    int ans = 0;

    for (int i = 0; i < n; ++i) {
        auto [a, b] = vec[i];

        for (int j = i + 1; j < n; ++j) {
            auto [c, d] = vec[j];

            int distx = a - c, disty = b - d;
            int sz = distx * distx + disty * disty;

            auto p = make_pair(a - disty, b + distx),
                 q = make_pair(c - disty, d + distx);

            if (us.contains(p) and us.contains(q)) ans = max(ans, sz);

            p = make_pair(a + disty, b - distx);
            q = make_pair(c + disty, d - distx);

            if (us.contains(p) and us.contains(q)) ans = max(ans, sz);
        }
    }

    cout << ans << endl;
}

int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}