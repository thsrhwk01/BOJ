#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

using ll = long long;

#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<bool> v(4);
    int ballCnt = 0, ans = 0;

    while (n--) {
        int cmd;
        cin >> cmd;

        switch (cmd) {
            case 1: {
                ballCnt += 1;

                break;
            }

            case 2: {
                ballCnt = 4;

                break;
            }

            case 3: {
                ballCnt += 1;

                if (v[3]) {
                    ans++;
                    v[3] = false;
                }

                if (v[2]) {
                    v[3] = true;
                    v[2] = false;
                }

                if (v[1]) {
                    v[2] = true;
                    v[1] = false;
                }

                break;
            }

            default:
                break;
        }

        if (ballCnt == 4) {
            ballCnt = 0;

            if (v[3] and v[2] and v[1]) {
                ans++;
                v[3] = false;
            }

            if (v[2] and v[1]) {
                v[3] = true;
                v[2] = false;
            }

            if (v[1]) {
                v[2] = true;
                v[1] = false;
            }

            v[1] = true;
        }
    }

    cout << ans;

    return 0;
}