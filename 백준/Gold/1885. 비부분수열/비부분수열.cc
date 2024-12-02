#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, ans = 0, cnt = 0;
    cin >> n >> k;

    vector<bool> vec(k);

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        if (!vec[tmp - 1]) {
            vec[tmp - 1] = true;
            ++cnt;

            if (cnt == k) {
                ++ans;
                cnt = 0;
                vec.flip();
            }
        }
    }

    cout << ans + 1;

    return 0;
}