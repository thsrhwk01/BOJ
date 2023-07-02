#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using tddd = tuple<double, double, double>;

#define endl '\n'
#define em emplace
#define emb emplace_back
#define all(x) x.begin(), x.end()
#define rep(i, from, to) for (int i = from; i <= to; ++i)
#define fastio                                                                 \
    iostream::sync_with_stdio(false);                                          \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);

const double pi = 3.14159265359;

int parents[1'001], gearNumber;

tddd gears[1'001];

double ans;

int findSet(int x) {
    return (parents[x] == x ? x : parents[x] = findSet(parents[x]));
}

void unionSet(int x, int y) {
    x = findSet(x);
    y = findSet(y);

    parents[max(x, y)] = min(x, y);
}

bool isConnected(int x, int y) { return findSet(x) == findSet(y); }

void input() {
    cin >> gearNumber;

    double x, y, r;
    rep(i, 0, gearNumber - 1) {
        cin >> x >> y >> r;

        gears[i] = make_tuple(x, y, r);
    }
}

double getDist(tddd a, tddd b) {
    auto [x1, y1, r1] = a;
    auto [x2, y2, r2] = b;

    return sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0));
}

double getConveyorLength(tddd a, tddd b) {
    double dist = getDist(a, b);

    auto [x1, y1, r1] = a;
    auto [x2, y2, r2] = b;

    if (dist - (r1 + r2) < 1e-9)
        return 0;

    r1 *= 2;
    r2 *= 2;

    return (pi / 2 * (r1 + r2)) +
           ((max(r1, r2) - min(r1, r2)) *
            asin((max(r1, r2) - min(r1, r2)) / 2 / dist)) +
           2 * sqrt(dist * dist - pow(max(r1, r2) - min(r1, r2), 2) / 4);
}

void solve() {
    // conveyor belt's lenght, gear1, gear2
    priority_queue<tuple<double, int, int>, vector<tuple<double, int, int>>,
                   greater<>>
        pq;

    rep(i, 0, gearNumber - 1) {
        parents[i] = i;

        rep(j, i + 1, gearNumber - 1) {
            pq.em(getConveyorLength(gears[i], gears[j]), i, j);
        }
    }

    while (!pq.empty()) {
        auto [len, gear1, gear2] = pq.top();
        pq.pop();

        if (isConnected(gear1, gear2))
            continue;

        ans += len;
        unionSet(gear1, gear2);
    }
}

void output() {
    cout.precision(14);
    cout << ans;
}

int main() {
    fastio;

    input();
    solve();
    output();
}
