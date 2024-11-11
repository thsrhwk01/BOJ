#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

#define endl '\n'

const long long INF = 5e8;

void solve() {
    int n;
    cin >> n;

    int i = 1;

    while (n--) {
        long long x, y;
        cin >> x >> y;
        cout << i << ' ' << x + 1 << ' ' << y + INF << endl;
        i++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}