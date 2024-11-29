#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> vec(n);

    long long sum = 0;

    for (auto &&x : vec) {
        cin >> x;
        sum += x;
    }

    long long avg = sum / n;

    queue<pair<int, int>> pq, mq;

    for (int i = 0; i < n; i++) {
        if (vec[i] > avg) {
            pq.emplace(i, vec[i] - avg);
        } else if (vec[i] < avg) {
            mq.emplace(i, avg - vec[i]);
        }
    }

    int mi, pi, mv = 0, pv = 0;
    long long ans = 0;

    while (true) {
        if (pq.empty() and mq.empty() and mv == 0 and pv == 0) {
            break;
        }

        if (mv <= 0) {
            tie(mi, mv) = mq.front();
            mq.pop();
        }

        if (pv <= 0) {
            tie(pi, pv) = pq.front();
            pq.pop();
        }

        ans += min(mv, pv) * (max(mi, pi) - min(mi, pi));

        auto tv = mv;
        mv -= pv;
        pv -= tv;
    }

    cout << ans;

    return 0;
}