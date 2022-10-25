#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    int two = 0, five = 0, ten = 0;

    for (int i = 1; i <=n; ++i) {
        int now = i;
        while (true) {
            if (now % 10 == 0) { ++ten; now /= 10; }
            else if (now % 5 == 0) { ++five; now /= 5; }
            else if (now % 2 == 0) { ++two; now /= 2; }
            else break;
        }
    }

    cout << ten + min(two, five);
}