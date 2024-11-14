#include <algorithm>
#include <iostream>

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

    for (long long i = 1; i < 0x3f3f3f3f; i++) {
        n *= 10;
        long long limit = 1;
        for (long long j = 0; j < i; j++) {
            limit *= 10;
        }

        for (long long j = 0; j < limit; j++) {
            long long ans = n + j;

            if (ans % lcm == 0) {
                cout << ans;

                return 0;
            }
        }
    }

    return 0;
}