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

int schedule[1'000'002], prefix_sum[1'000'002];

void input() {
    int nCount;
    cin >> nCount;

    int startSecond, endSecond;

    while (nCount--) {
        cin >> startSecond >> endSecond;
        schedule[startSecond]++;
        schedule[endSecond + 1]--;
    }
}

void solve() {
    for (int i = 1; i < 1'000'001; i++)
        prefix_sum[i] = prefix_sum[i - 1] + schedule[i];
}

void output() {
    int qCount, qSecond;
    cin >> qCount;

    while (qCount--) {
        cin >> qSecond;
        cout << prefix_sum[qSecond] << endl;
    }
}

int main() {
    fastio;

    input();
    solve();
    output();
}