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

    queue<int> odds, evens;

    rep(i, 1, n) {
        int x, y;
        cin >> x >> y;

        if ((x + y) & 1) {
            odds.em(i);
        } else {
            evens.em(i);
        }
    }

    if (odds.empty() or evens.empty()) {
        cout << "NO";
        return 0;
    }

    cout << "YES" << endl;

    while (!odds.empty()) {
        cout << odds.front() << ' ';
        odds.pop();
    }

    while (!evens.empty()) {
        cout << evens.front() << ' ';
        evens.pop();
    }

    return 0;
}