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

struct Pillar {
    int x = 0, y = 0, range = 0;
    bool isSmell = false;
};

vector<Pillar> pillars(3'005);
bool isVisited[3'005];
int shiruRange, n, m;

inline int getDist(int x1, int y1, int x2, int y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

void dfs(int pillarNumber) {
    auto &aPillar = pillars[pillarNumber];
    int x1 = aPillar.x, y1 = aPillar.y;

    rep(i, 1, n) {
        if (isVisited[i] or i == pillarNumber) {
            continue;
        }

        auto &bPillar = pillars[i];
        int x2 = bPillar.x, y2 = bPillar.y;

        if (getDist(x1, y1, x2, y2) <= shiruRange) {
            isVisited[i] = true;
            dfs(i);
        }
    }
}

int main() {
    fastio;

    cin >> n >> m;

    rep(i, 1, n) { cin >> pillars[i].x >> pillars[i].y; }

    vi markedNumber;
    markedNumber.emb(0);

    rep(i, 1, m) {
        int tmp;
        cin >> tmp;
        markedNumber.emb(tmp);
    }

    cin >> shiruRange;
    shiruRange *= shiruRange;

    rep(i, 1, m) {
        int tmp;
        cin >> tmp;

        pillars[markedNumber[i]].range =
            max(pillars[markedNumber[i]].range, tmp * tmp);
    }

    rep(i, 1, m) {
        auto &aPillar = pillars[markedNumber[i]];
        int x1 = aPillar.x, y1 = aPillar.y, range = aPillar.range;

        rep(i, 1, n) {
            auto &bPillar = pillars[i];
            int x2 = bPillar.x, y2 = bPillar.y;

            if (getDist(x1, y1, x2, y2) <= range) {
                bPillar.isSmell = true;
            }
        }
    }

    rep(i, 1, n) {
        if (!isVisited[i] and !pillars[i].isSmell) {
            isVisited[i] = true;
            dfs(i);
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