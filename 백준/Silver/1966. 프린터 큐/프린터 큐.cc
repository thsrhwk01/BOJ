//
// Created by ㅇㅇ on 2022-07-26.
//

#include <queue>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    while (n--) {
        int m, what; cin >> m >> what;

        queue<int> q;
        unordered_map<int, int> prior;

        for (int i = 0; i < m; ++i) {
            int priority; cin >> priority;
            q.push(i);
            prior[i] = priority;
        }

        int cnt = 0;
        while(!q.empty()) {
            auto x = q.front();
            q.pop();
            const auto highest =
                    max_element(prior.begin(), prior.end(),
                                [] (const auto& lhs, const auto& rhs) {
                        return lhs.second < rhs.second;
                    });

            //cout << highest->first << ":" << highest->second << '\t';

            if (prior[x] == highest->second) {
                ++cnt;
                if (x == what) { cout << cnt << '\n'; break; }
                prior.erase(x);
            } else {
                q.push(x);
            }
        }
    }
}