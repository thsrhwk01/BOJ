#include <functional>
#include <iostream>
#include <string>

using namespace std;

#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    string s;
    cin >> s;

    long long ans = 0;

    function<long long(int)> calc = [&](int i) {
        return i >= n ? 1 : (1 + 26 * calc(i + 1));
    };

    for (int i = 0; i < s.size(); i++) {
       ans += (long long)(s[i] - 'a') * calc(i + 1) + 1;
    }

    cout << ans;

    return 0;
}