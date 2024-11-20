#include <cmath>
#include <iostream>
#include <vector>

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
    return (ccw(a, b, c) * ccw(a, b, d) <= 0) and
           (ccw(c, d, a) * ccw(c, d, b) <= 0);
}

double getDist(pll a, pll b) {
    ll res = (b.first - a.first) * (b.first - a.first) +
             (b.second - a.second) * (b.second - a.second);

    return sqrt(res);
}

vector<pll> visited;

void bt(double dist) {
    if (visited.size() == n) {
        ans = min(ans, dist + getDist(visited.back(), visited.front()));
        return;
    }

    pll c;
    if (!visited.empty()) {
        c = visited.back();
    }

    for (int i = 0; i < points.size(); i++) {
        pll d = points[i];
        double tDist = dist;

        for (const auto &p : visited) {
            if (p == d) goto E;
        }

        if (!visited.empty()) {
            for (int j = 1; j < visited.size() - 1; j++) {
                pll a = visited[j - 1], b = visited[j];

                if (isCross(a, b, c, d)) {
                    goto E;
                }
            }
        }

        visited.emplace_back(d);

        if (visited.size() > 1) {
            tDist += getDist(c, d);
        }
        bt(tDist);

        visited.pop_back();

    E: {}
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
    cout << fixed << ans;

    return 0;
}