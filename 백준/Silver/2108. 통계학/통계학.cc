//
// Created by woo-young Choi on 2022/08/13.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;

struct cmp {
    bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs) {
        if (lhs.second == rhs.second) return lhs.first > rhs.first;
        return lhs.second < rhs.second;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;

    int high = -4000, low = 4000; double sum = 0;

    vector<int> ints(n);
    for (auto& x : ints) {
        cin >> x;
        sum += x;
        if (x < low) low = x;
        if (x > high) high = x;
    }

    sort(ints.begin(), ints.end());

    sum = round(sum/double(n));
    if (sum == 0) sum = 0;
    cout << sum << '\n' << ints[n/2] << '\n';

    if (n == 1) cout << ints[0] << '\n';
    else {
        map<int, int> m;
        for (const auto& x : ints) {
            m[x]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
        for (const auto& x : m) {
            q.emplace(x.first, x.second);
        }

        const auto fir = q.top();
        q.pop();
        const auto sec = q.top();
        if (fir.second == sec.second) cout << sec.first << '\n';
        else cout << fir.first << '\n';
    }

    cout << high - low;
}