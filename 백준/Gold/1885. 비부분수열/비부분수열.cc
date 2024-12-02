#include <iostream>
#include <set>

using namespace std;

#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, ans = 0;
    cin >> n >> k;

    set<int> s;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        s.emplace(tmp);

        if (s.size() == k) {
            ++ans;
            s.clear();
        }
    }

    cout << ans + 1;

    return 0;
}