#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <vector>

#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n, m;
    cin >> n >> m;

    vector<long long> vec(n);

    for (auto &&i : vec) {
        cin >> i;
    }

    sort(vec.begin(), vec.end());

    while (m--) {
        long long cmd, i, j, k;
        cin >> cmd;

        switch (cmd) {
            case 1: {
                cin >> k;
                auto it = lower_bound(vec.begin(), vec.end(), k);

                cout << vec.end() - it << endl;

                break;
            }

            case 2: {
                cin >> k;
                auto it = upper_bound(vec.begin(), vec.end(), k);
                cout << vec.end() - it << endl;

                break;
            }

            case 3: {
                cin >> i >> j;

                auto it1 = lower_bound(vec.begin(), vec.end(), i);
                auto it2 = upper_bound(vec.begin(), vec.end(), j);

                cout << it2 - it1 << endl;

                break;
            }

            default:
                break;
        }
    }

    return 0;
}