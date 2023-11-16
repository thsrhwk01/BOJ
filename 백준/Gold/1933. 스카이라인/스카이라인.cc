#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using tiii = tuple<int, int, int>;

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
    // fastio;

    int n;
    cin >> n;

    auto cmp = [](tiii l, tiii r) {
        swap(get<0>(l), get<0>(r));
        return l < r;
    };

    // x, isStart, height
    priority_queue<tiii, vector<tiii>, decltype(cmp)> pq;

    rep(i, 1, n) {
        int l, h, r;

        cin >> l >> h >> r;

        pq.em(l, 1, h);
        pq.em(r, 0, h);
    }

    multiset<int, greater<>> heights;
    heights.em(0);
    vii ans;

    while (!pq.empty()) {
        auto [x, isStart, curHeight] = pq.top();
        pq.pop();

        if (isStart == 1) {
            heights.em(curHeight);

            // 건물 시작점에서의 최대 높이를 정답 목록에 저장
            ans.emb(x, *heights.begin());
        } else {
            heights.erase(heights.find(curHeight));

            if (pq.empty() or get<0>(pq.top()) > x) {
                ans.emb(x, *heights.begin());
            }
        }
    }

    int lastHeight = -1;
    for (const auto &p : ans) {
        if (lastHeight != p.second) {
            cout << p.first << ' ' << p.second << ' ';
            lastHeight = p.second;
        }
    }
}