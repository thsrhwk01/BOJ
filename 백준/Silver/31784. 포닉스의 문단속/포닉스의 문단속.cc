#include <iostream>
#include <string>

using namespace std;

#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    for (auto &&c : s) {
        int x = ('Z' - c + 1) % 26;

        if (k >= x) {
            k-= x;
            c = 'A';
        }
    }

    k %= 26;

    s.back() = ((s.back() - 'A' + k) % 26) + 'A';

    cout << s;

    return 0;
}