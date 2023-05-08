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
#define fastio                                                                 \
    iostream::sync_with_stdio(false);                                          \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);

int ansBreaking, ansCount = 1, widthMeter, heightMeter, blockCounts[5'000'005],
                 prefix_sum[5'000'005];

void input() {
    cin >> widthMeter >> heightMeter;

    bool isBottom = false;

    int lengthMeter;
    for (int i = 0; i < widthMeter; i++) {
        cin >> lengthMeter;

        if (isBottom) {
            blockCounts[0]++;
            blockCounts[lengthMeter]--;
        } else {
            blockCounts[heightMeter - lengthMeter]++;
        }

        isBottom = !isBottom;
    }
}

void solve() {
    prefix_sum[0] = blockCounts[0];
    ansBreaking = prefix_sum[0];

    for (int i = 1; i < heightMeter; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + blockCounts[i];

        if (prefix_sum[i] < ansBreaking) {
            ansBreaking = prefix_sum[i];
            ansCount = 1;
        } else if (prefix_sum[i] == ansBreaking)
            ++ansCount;
    }
}

void output() {
    cout << ansBreaking << ' ' << ansCount;
}

int main() {
    fastio;

    input();
    solve();
    output();
}