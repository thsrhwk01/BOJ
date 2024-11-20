#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define endl '\n'

using ll = long long;
using pll = pair<ll, ll>;

vector<pll> points;

double ans = 0x7f7f7f7f7f7f7f7f;
int n;

int ccw(pll a, pll b, pll c) {
    pll ab = make_pair(b.first - a.first, b.second - a.second),
        bc = make_pair(c.first - b.first, c.second - b.second);

    ll res = ab.first * bc.second - ab.second * bc.first;

    if (res > 0) {
        return 1;
    } else if (res == 0) {
        return 0;
    } else {
        return -1;
    }
}

bool isCross(pll a, pll b, pll c, pll d) {
    return (ccw(a, b, c) * ccw(a, b, d) < 0) and
           (ccw(c, d, a) * ccw(c, d, b) < 0);
}

double getDist(pll a, pll b) {
    ll res = (b.first - a.first) * (b.first - a.first) +
             (b.second - a.second) * (b.second - a.second);

    return sqrt(res);
}

vector<int> visited;

void bt(double dist) {
    if (visited.size() == n) {
        ans = min(ans, dist + getDist(points[visited.back()],
                                      points[visited.front()]));

        return;
    }

    pll c;
    if (!visited.empty()) {
        c = points[visited.back()];
    }

    for (int i = 0; i < points.size(); i++) {
        if (find(visited.begin(), visited.end(), i) != visited.end()) {
            continue;
        }

        pll d = points[i];

        bool crossed = false;
        if (visited.size() > 3)
            for (int j = 1; j < visited.size() - 1; j++) {
                pll a = points[j - 1], b = points[j];

                if (isCross(a, b, c, d)) {
                    crossed = true;
                    continue;
                }
            }

        if (crossed) {
            continue;
        }

        visited.emplace_back(i);

        double tDist = dist;
        if (visited.size() > 1) {
            tDist += getDist(c, d);
        }

        bt(tDist);

        visited.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    points.resize(n);

    for (auto &&point : points) {
        cin >> point.first >> point.second;
    }

    bt(0);

    cout.precision(12);
    cout << fixed;

    cout << ans;

    return 0;
}