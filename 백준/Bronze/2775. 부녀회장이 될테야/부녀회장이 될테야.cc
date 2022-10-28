#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t; cin >> t;
    vector<int> k, n;

    while (t--) {
        int k_n, n_n; cin >> k_n >> n_n;
        k.push_back(k_n); n.push_back(n_n);
    }
    auto k_max = *max_element(k.begin(), k.end());
    auto n_max = *max_element(n.begin(), n.end());

    vector<vector<int>> apt(k_max + 1, vector<int>(n_max + 1));
    for (int i = 0; i <= k_max; ++i) {
        for (int j = 0; j <= n_max; ++j) {
            if (j == 0) apt[i][j] = 0;
            else if (i == 0) {
                apt[i][j] = j;
            }
            else {
                apt[i][j] = 0;
                for (int l = 1; l <= j; ++l) {
                    apt[i][j] += apt[i-1][l];
                }
            }
        }
    }

    for (int i = 0; i < k.size(); ++i) {
        cout << apt[k[i]][n[i]] << '\n';
    }
}