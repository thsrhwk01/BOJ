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

int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    queue<int> visitingQ;

    rep(i, 1, n) {
        int t;
        cin >> t;

        visitingQ.em(t);
    }

    int bowl = 0;
    bool isAble = true;

    queue<int> reservedQ;

    rep(now, 0, 2'000'005) {
        // 손님 다 받았으면 끝
        if (visitingQ.empty() and reservedQ.empty()) {
            break;
        }

        // 손님 도착시점
        if (!reservedQ.empty() and reservedQ.front() == now) {
            reservedQ.pop();

            continue;
        }

        // 손님 도착했는데 커피 준비 안됨
        if (!visitingQ.empty() and visitingQ.front() == now) {
            isAble = false;

            break;
        }

        // 손님 도착 M분 이내
        if (!visitingQ.empty() and visitingQ.front() - m <= now) {
            if (bowl > 0) {
                --bowl;
                reservedQ.em(visitingQ.front());
                visitingQ.pop();
                
                continue;
            }
        }

        ++bowl;
    }

    cout << (isAble ? "success" : "fail");
}