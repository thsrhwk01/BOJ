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

    char c;

    while (cin >> c) {
        if (c == 'w') {
            cout << "chunbae";
            return 0;
        }

        if (c == 'b') {
            cout << "nabi";
            return 0;
        }

        if (c == 'g') {
            cout << "yeongcheol";
            return 0;
        }
    }
}