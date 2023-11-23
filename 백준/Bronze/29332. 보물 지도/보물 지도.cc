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

int main() {
    fastio;

    ll x1 = 0x3f3f3f3f3f3f3f3f, x2 = -0x3f3f3f3f3f3f3f3f,
       y1 = 0x3f3f3f3f3f3f3f3f, y2 = -0x3f3f3f3f3f3f3f3f;

    int n;
    cin >> n;

    ll x, y;
    char c;

    while (n--) {
        cin >> x >> y >> c;

        switch (c) {
        case 'L':
            x1 = min(x1, x);
            break;
        case 'R':
            x2 = max(x2, x);
            break;
        case 'U':
            y2 = max(y2, y);
            break;
        case 'D':
            y1 = min(y1, y);
            break;
        default:
            break;
        }
    }

    if (x1 == 0x3f3f3f3f3f3f3f3f or x2 == -0x3f3f3f3f3f3f3f3f or
        y1 == 0x3f3f3f3f3f3f3f3f or y2 == -0x3f3f3f3f3f3f3f3f) {
        cout << "Infinity";
        return 0;
    }

    ll dx, dy, mul;

    dx = x1 - x2 - 1;
    dy = y1 - y2 - 1;

    mul = dx * dy;
    
    cout << mul;
}