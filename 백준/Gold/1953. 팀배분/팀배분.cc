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

    int n;
    cin >> n;

    vi edges[105];

    rep(i, 1, n) {
        int cnt;
        cin >> cnt;

        while (cnt--) {
            int x;
            cin >> x;

            edges[i].emb(x);
        }
    }

    vi w, b;

    set<int> remain;
    rep(i, 1, n) { remain.em(i); }

    queue<pair<int, bool>> q;

    while (!remain.empty()) {
        q.em(*remain.begin(), true);
        remain.erase(remain.begin());

        while (!q.empty()) {
            auto [number, isWhite] = q.front();
            q.pop();

            if (isWhite) {
                w.emb(number);
            } else {
                b.emb(number);
            }

            for (auto nextNumber : edges[number]) {
                if (remain.find(nextNumber) != remain.end()) {
                    remain.erase(remain.find(nextNumber));
                    q.em(nextNumber, !isWhite);
                }
            }
        }
    }
    sort(all(w));
    sort(all(b));

    cout << w.size() << endl;
    for (auto x : w) {
        cout << x << ' ';
    }

    cout << endl;

    cout << b.size() << endl;
    for (auto x : b) {
        cout << x << ' ';
    }
}