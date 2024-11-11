#include <iostream>
#include <algorithm>
#include <numeric>
#include <cstdlib>

using namespace std;

using ll = long long;

#define endl '\n'

void solve() {
    ll a, b;
    cin >> a >> b;

    cout << (b > a and b % a == 0) << endl;

    return;
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