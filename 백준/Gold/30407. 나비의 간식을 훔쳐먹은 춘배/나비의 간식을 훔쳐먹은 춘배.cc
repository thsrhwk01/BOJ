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

int ans = -1, n, damage[20], h, d, k;

void recursion(int step, int health, int dist, bool avoidAvailable,
               bool isParryingReady) {
    if (health <= 0) {
        return;
    }

    if (step > n) {
        ans = max(ans, health);
        return;
    }

    int halfDamage =
            ((damage[step] - dist) >= 0 ? (damage[step] - dist) : 0) / 2,
        movingDamage =
            ((damage[step] - dist - k) >= 0 ? (damage[step] - dist - k) : 0);

    if (isParryingReady) {
        halfDamage = 0;
        movingDamage = 0;
    }

    recursion(step + 1, health - halfDamage, dist, avoidAvailable, false);
    recursion(step + 1, health - movingDamage, dist + k, avoidAvailable, false);
    if (avoidAvailable) {
        recursion(step + 1,
                  health - (damage[step] - dist >= 0 ? damage[step] - dist : 0),
                  dist, false, true);
    }
}

int main() {
    fastio;

    cin >> n;

    cin >> h >> d >> k;

    rep(i, 1, n) { cin >> damage[i]; }

    recursion(1, h, d, true, false);

    cout << ans;
}