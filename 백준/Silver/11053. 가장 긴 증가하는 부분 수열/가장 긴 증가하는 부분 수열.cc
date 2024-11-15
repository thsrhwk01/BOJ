#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> finder;

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        auto idx =
            lower_bound(finder.begin(), finder.end(), x) - finder.begin();

        ans = max(ans, int(idx + 1));

        if (idx == finder.size()) {
            finder.emplace_back(x);
        } else {
            finder[idx] = x;
        }
    }

    cout << ans;

    return 0;
}