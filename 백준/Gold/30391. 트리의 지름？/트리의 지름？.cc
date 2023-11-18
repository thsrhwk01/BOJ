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

    int n, k;
    cin >> n >> k;

    queue<int> q;
    q.em(1);

    int printNode = 2;

    while (true) {
        int now = q.front();
        q.pop();

        int limit = (now == 1 ? k : k - 1);

        // cout << now << endl;

        while (limit--) {
            q.em(printNode);
            cout << now << ' ' << printNode << endl;
            ++printNode;

            if (printNode == n + 1) {
                return 0;
            }
        }
    }
}