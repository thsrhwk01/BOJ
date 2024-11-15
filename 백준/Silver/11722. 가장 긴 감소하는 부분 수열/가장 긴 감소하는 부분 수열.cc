#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl '\n';

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int ans = 0;
    vector<int> finder;

    while (n--) {
        int x;
        cin >> x;
        x = -x;

        int idx = lower_bound(finder.begin(), finder.end(), x) - finder.begin();

        ans = max(ans, idx + 1);

        if (idx == finder.size()) {
            finder.emplace_back(x);
        } else {
            finder[idx] = x;
        }
    }

    cout << ans;

    return 0;
}