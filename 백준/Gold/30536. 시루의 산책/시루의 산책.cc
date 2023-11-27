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

inline int getDist(int x1, int y1, int x2, int y2) {
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    vii coors;
    coors.emb(0, 0);
    rep(i, 1, n) {
        int x, y;
        cin >> x >> y;

        coors.emb(x, y);
    }

    vi pillars;
    pillars.emb(0);
    rep(i, 1, m) {
        int pillar;
        cin >> pillar;

        pillars.emb(pillar);
    }

    vi ranges(3'005);
    fill(all(ranges), 0);
    rep(i, 0, m) {
        int range;
        cin >> range;

        range = range * range;

        ranges[pillars[i]] = max(ranges[pillars[i]], range);
    }

    bool isAble[3'005];
    memset(isAble, true, sizeof(isAble));
    vi edges[3'005];

    rep(i, 1, n) {
        int range = ranges[i];
        auto [x1, y1] = coors[i];

        if (range > 0) {
            isAble[i] = false;
        }

        rep(j, 1, n) {
            if (i == j) {
                continue;
            }

            auto [x2, y2] = coors[j];
            int dist = getDist(x1, y1, x2, y2);

            if (dist <= ranges[0]) {
                edges[i].emb(j);
            }

            if (range > 0 and dist <= range) {
                isAble[j] = false;
            }
        }
    }

    bool isVisited[3'005];
    memset(isVisited, false, sizeof(isVisited));
    queue<int> q;

    rep(i, 1, n) {
        if (isAble[i]) {
            q.em(i);
            isVisited[i] = true;
        }
    }

    while (!q.empty()) {
        auto now = q.front();
        q.pop();

        for (const auto &edge : edges[now]) {
            if (isVisited[edge]) {
                continue;
            }

            isVisited[edge] = true;
            q.em(edge);
        }
    }

    int ans = 0;
    rep(i, 1, n) {
        if (isVisited[i]) {
            ++ans;
        }
    }

    cout << ans;
}