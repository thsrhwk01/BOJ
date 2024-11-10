#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <tuple>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;
    cin >> a >> b;

    vector<pair<int, int>> vec;
    bool isAble = false;

    while (a > 0 and b > 0) {
        if (a - b == 1) {
            isAble = true;
            vec.emplace_back(a, b);

            break;
        }

        vec.emplace_back(2, 1);
        a -= 2;
        b -= 1;
    }

    if (isAble) {
        cout << "YES" << endl << vec.size() << endl;

        for (const auto &[x, y] : vec) {
            for (int i = 0; i < y; i++) {
                cout << "ab";
            }
            cout << 'a' << endl;
        }

    } else {
        cout << "NO";
    }

    return 0;
}