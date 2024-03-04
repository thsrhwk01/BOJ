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
#define fastio                        \
    iostream::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

int n, HP, ans = 0x3f3f3f3f;

vector<int> coolTime, recTime, damage;

void backtracking(int nowTime, int remainHP) {
    if (nowTime > ans) return;

    if (remainHP <= 0) {
        ans = min(ans, nowTime);

        return;
    }

    for (int i = 0; i < n; ++i) {
        int nextTime = max(nowTime, recTime[i]);
        int recTimeTmp = recTime[i];

        recTime[i] = nextTime + coolTime[i];

        backtracking(nextTime + 1, remainHP - damage[i]);

        recTime[i] = recTimeTmp;
    }
}

int main() {
    fastio;

    cin >> n >> HP;

    coolTime.resize(n);
    recTime.resize(n);
    damage.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> coolTime[i] >> damage[i];
    }

    backtracking(0, HP);

    cout << ans;

    return 0;
}