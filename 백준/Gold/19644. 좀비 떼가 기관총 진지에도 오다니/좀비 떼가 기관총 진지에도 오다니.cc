#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int main() {
    cin.tie(NULL)->sync_with_stdio(false);

    int l, m, atk, c;

    cin >> l >> m >> atk >> c;

    vector<bool> bUsed(l);

    int atkNow = 0;

    for (int i = 0; i < l; ++i) {
        int hp;
        cin >> hp;

        if (i >= m and !bUsed[i - m]) {
            atkNow -= atk;
        }

        if (atkNow + atk >= hp) {
            bUsed[i] = false;

            atkNow += atk;
        } else if (c) {
            bUsed[i] = true;

            --c;
        } else {
            cout << "NO";

            return 0;
        }
    }

    cout << "YES";

    return 0;
}