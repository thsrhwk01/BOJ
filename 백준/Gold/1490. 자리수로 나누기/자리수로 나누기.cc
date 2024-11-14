#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

#define endl '\n'

int gcd(int x, int y) {
    if (x < y) {
        swap(x, y);
    }

    return x % y ? gcd(y, x % y) : y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n;
    cin >> n;

    long long lcm = 1, tmp = n;
    while (tmp) {
        int x = tmp % 10;
        tmp /= 10;

        if (x == 0) {
            continue;
        }

        lcm = lcm * x / gcd(lcm, x);
    }

    if (n % lcm == 0) {
        cout << n;

        return 0;
    }

    string str1 = to_string(n);
    long long i = 0;

    for (int i = 1; i < 0x3f3f3f3f; i++) {
        string prefix;
        for (int j = 0; j < i; j++) {
            prefix.append("0");
        }

        for (long long j = 0; j < 0x3f3f3f3f; j++) {
            string str2 = to_string(j);

            if (str2.size() > i) {
                break;
            }

            if (str2.size() + prefix.size() > i) {
                prefix.pop_back();
            }

            string ans = str1 + prefix + str2;

            if (stoll(ans) % lcm == 0) {
                cout << ans;
                return 0;
            }
        }
    }

    return 0;
}