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

    bool ans = true;
    int n, m, k;
    cin >> n >> m >> k;

    vii edges[300'005];

    rep(i, 1, m) {
        ll from, to, weight;

        cin >> from >> to >> weight;

        edges[from].emb(to, weight);
        edges[to].emb(from, weight);

        if ((weight * 2) % k != 0) {
            ans = false;
        }
    }

    set<int> a, b;
    bool isVisited[300'003];
    memset(isVisited, false, sizeof(isVisited));

    priority_queue<tuple<ll, ll>> q;

    int start = 1;
    while (true) {
        if (start > n) {
            break;
        }

        if (isVisited[start]) {
            start++;
            continue;
        }

        isVisited[start] = true;
        a.em(start);
        q.em(start, 0);

        while (!q.empty()) {
            auto [now, sum] = q.top();
            q.pop();

            for (const auto &p : edges[now]) {
                auto [to, weight] = p;

                bool nextCheck = (sum + weight) % k == 0;

                // cout << now << ' ' << to << ' ' << nextCheck << endl;

                if (!isVisited[to]) {
                    if (nextCheck) {
                        a.em(to);
                    } else {
                        b.em(to);
                    }

                    q.em(to, sum + weight);
                    isVisited[to] = true;

                    continue;
                }

                if (nextCheck) {
                    if (b.find(to) != b.end()) {
                        // cout << "XXXXX   " << now << ' ' << to << endl;
                        ans = false;
                    }
                } else {
                    if (a.find(to) != a.end()) {
                        // cout << "YYYYY   " << now << ' ' << to << endl;
                        ans = false;
                    }
                }
            }
        }
    }

    cout << (ans ? "Yes" : "No");
}