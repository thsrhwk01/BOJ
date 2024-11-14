#include <iostream>
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

    vector<bool> isVisited(n + 1);

    queue<vector<int>> q;

    vector<int> vec;
    vec.emplace_back(n);
    q.emplace(vec);
    isVisited[n] = true;

    while (!q.empty()) {
        auto ls = q.front();
        q.pop();

        auto x = ls.back();

        if (x == 1) {
            cout << ls.size() - 1 << endl;

            for (auto &&i : ls) {
                cout << i << ' ';
            }

            return 0;
        }

        if (x % 3 == 0 and !isVisited[x / 3]) {
            isVisited[x / 3] = true;
            ls.emplace_back(x / 3);

            q.emplace(ls);
            ls.pop_back();
        }

        if (x % 2 == 0 and !isVisited[x / 2]) {
            isVisited[x / 2] = true;
            ls.emplace_back(x / 2);

            q.emplace(ls);
            ls.pop_back();
        }

        if (!isVisited[x - 1]) {
            isVisited[x - 1] = true;
            ls.emplace_back(x - 1);

            q.emplace(ls);
            ls.pop_back();
        }
    }

    return 0;
}