#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;

#define endl '\n'
#define em emplace
#define emb emplace_back
#define all(x) x.begin(), x.end()
#define rep(i, from, to) for (int i = from; i <= to; ++i)
#define fastio                                                                 \
    iostream::sync_with_stdio(false);                                          \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);

pll startPoint;

int pointNumber, ans;

vector<pair<ll, ll>> pointArray;

inline int ccw(pll &a, pll &b, pll &c) {
    ll res = (a.first * b.second + b.first * c.second + c.first * a.second) -
              (b.first * a.second + c.first * b.second + a.first * c.second);

    if (res > 0)
        return 1;
    if (res < 0)
        return -1;
    return 0;
}

inline ll dist(pll &a, pll &b) {
    return (a.first - b.first) * (a.first - b.first) +
           (a.second - b.second) * (a.second - b.second);
}

bool cmp(pll &a, pll &b) {
    int res = ccw(startPoint, a, b);

    switch (res) {
    case 0:
        return dist(startPoint, b) > dist(startPoint, a);
    case 1:
        return true;
    default:
        return false;
    }
}

void input() {
    cin >> pointNumber;

    ll x, y;
    rep(i, 1, pointNumber) {
        cin >> x >> y;

        pointArray.emb(x, y);
    }
}

void solve() {
    // Find start point
    auto it = min_element(all(pointArray), [&](auto b, auto a) {
        swap(b.first, b.second);
        swap(a.first, a.second);
        swap(b.second, a.second);

        return b < a;
    });

    startPoint = *it;

    sort(all(pointArray), cmp);

    stack<pll> stk;
    stk.em(startPoint);
    stk.em(pointArray.front());

    int next = 1;

    while (next < pointArray.size()) {
        auto nextPoint = pointArray[next];
        while (stk.size() >= 2) {

            auto b = stk.top();
            stk.pop();
            auto a = stk.top();

            if (ccw(a, b, nextPoint) > 0 ) {
                stk.em(b);
                break;
            }
        }

        stk.em(nextPoint);
        ++next;
    }

    ans = stk.size();
}

void output() {
    cout << ans;
}

int main() {
    fastio;

    input();
    solve();
    output();
}