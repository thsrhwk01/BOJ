#include <functional>
#include <iostream>
#include <queue>
#include <vector>

#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, s, m;
    cin >> n >> s >> m;

    vector<int> vec(m);
    for (auto &&x : vec) cin >> x;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    for (int i = 0; i < m; ++i) {
        pq.emplace(vec[i], i);

        --n;
        if (n == s) {
            cout << i + 1;

            return 0;
        }
    }

    while (true) {
        auto [t, idx] = pq.top();
        pq.pop();

        --n;
        if (n == s) {
            cout << idx +1 ;

            return 0;
        }

        pq.emplace(t + vec[idx], idx);
    }

    return 0;
}