#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    priority_queue<long long, vector<long long>, greater<long long>> pq;

    while (n--) {
        long long tmp;
        cin >> tmp;
        pq.emplace(tmp);
    }

    long long ans = 0;

    while (pq.size() > 1) {
        auto a = pq.top();
        pq.pop();
        auto b = pq.top();
        pq.pop();

        ans += a * b;
        pq.emplace(a + b);
    }

    cout << ans;

    return 0;
}