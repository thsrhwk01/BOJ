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

int ans = 0x3f3f3f3f, sequence[100'005], sequenceSize, minimum;

void input() {
    cin >> sequenceSize >> minimum;

    rep(i, 1, sequenceSize) cin >> sequence[i];
}

void solve() {
    int leftIndex = 1, rightIndex = 1, sum = 0;

    while (rightIndex <= sequenceSize) {
        sum += sequence[rightIndex];

        while (sum >= minimum) {
            ans = min(ans, rightIndex - leftIndex + 1);
            sum -= sequence[leftIndex++];
        }

        ++rightIndex;
    }
}

void output() { cout << (ans != 0x3f3f3f3f ? ans : 0); }

int main() {
    fastio;

    input();
    solve();
    output();
}