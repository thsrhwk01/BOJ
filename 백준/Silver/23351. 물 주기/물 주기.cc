#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

#define endl '\n'

using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, a, b;
    cin >> n >> k >> a >> b;

    ll ans = 0;

    int cycle = n / a;

    
    while (true) {
        if (k < cycle) {
            ans += k;
            
            break;
        }

        ans += cycle;

        k -= (cycle - b);
    }

    cout << ans;
}