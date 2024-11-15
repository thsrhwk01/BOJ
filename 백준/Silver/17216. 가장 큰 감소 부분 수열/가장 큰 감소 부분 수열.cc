#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> vec(n), dp(n);

    for (auto&& i : vec) {
        cin >> i;
    }

    for (int i = 0; i < n; i++) {
        int sum = 0, x = vec[i];
        
        for (int j = 0; j < i; j++) {
            if (x < vec[j]) {
                sum = max(sum, dp[j]);
            }
        }
        
        dp[i] = sum + x;
    }

    cout << *max_element(dp.begin(), dp.end());

    return 0;
}