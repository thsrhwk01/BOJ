#include <bits/stdc++.h>

using namespace std;

using ll  = long long;
using vi  = vector<int>;
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
    cout.tie(nullptr);                                                         \

bool checker[11'000];

void input() {
    
}

void solve() {
    rep(i, 1, 10'000) {
        if (!checker[i]) cout << i << endl;

        int tmp = i, target = i;
        while (tmp > 0) {
            target += tmp % 10;
            tmp /= 10;
        }
        checker[target] = true;
    }
}

void output() {
    
}

int main() {
    fastio;

    input();
    solve();
    output();
}