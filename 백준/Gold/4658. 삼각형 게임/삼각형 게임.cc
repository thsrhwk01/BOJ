#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <list>
#include <numeric>

using namespace std;

#define endl '\n'

vector<int> lefts, rights, outs, idxs;
vector<vector<int>> tris(6);

int ans;

void backtracking(int idx) {
    idxs.emplace_back(idx);
    const auto &tri = tris[idx];

    for (int i = 0; i < 3; i++) {
        int left = tri[i % 3], right = tri[(i + 1) % 3], out = tri[(i + 2) % 3];

        if (!rights.empty() and rights.back() != left) {
            continue;
        }

        lefts.emplace_back(left);
        rights.emplace_back(right);
        outs.emplace_back(out);

        if (idxs.size() < 6) {
            for (int j = 0; j < 6; j++) {
                if (find(idxs.begin(), idxs.end(), j) != idxs.end()) {
                    continue;
                }

                backtracking(j);
            }
        } else if (lefts.front() == right) {
            ans = max(ans, accumulate(outs.begin(), outs.end(), 0));
        }

        lefts.pop_back();
        rights.pop_back();
        outs.pop_back();
    }

    idxs.pop_back();
}

void solve() {
    ans = -1;

    for (auto &&tri : tris) {
        tri.clear();

        for (int i = 0; i < 3; i++) {
            int x;
            cin >> x;

            tri.emplace_back(x);
        }
    }

    for (int i = 0; i < 6; i++) {
        backtracking(i);
    }

    if (ans == -1) {
        cout << "none" << endl;
    } else {
        cout << ans << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        solve();

        char c;
        cin >> c;

        if (c == '$') {
            return 0;
        }
    }

    return 0;
}