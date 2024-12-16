#include <iostream>
#include <numeric>
#include <vector>
#include <queue>

using namespace std;

#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    auto vec = vector<vector<int>>(n);

    for (auto &&row : vec) {
        for (int i = 0; i < n; ++i) {
            bool x;
            cin >> x;

            if (x) {
                row.emplace_back(i);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        vector<bool> isVisited(n);

        queue<int> q;
        q.emplace(i);

        while (!q.empty()){
            auto x = q.front();
            q.pop();

            for (auto y : vec[x]) {
                if (isVisited[y]) {
                    continue;
                }

                isVisited[y] = true;
                q.emplace(y);
            }
        }
        
        for (auto &&vis : isVisited) {
            cout << vis << ' ' ;
        }

        cout << endl;
    }

    return 0;
}