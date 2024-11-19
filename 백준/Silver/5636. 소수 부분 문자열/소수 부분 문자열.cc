#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<bool> era(100'000);
    fill(era.begin(), era.end(), true);

    era[0] = false;
    era[1] = false;

    for (int i = 2; i < 100'000; i++) {
        if (!era[i]) {
            continue;
        }

        int tmp = i * 2;

        while (tmp < 100'000) {
            era[tmp] = false;

            tmp += i;
        }
    }

    string s;
    while (cin >> s) {
        if (s == "0") {
            break;
        }

        int m = 0;

        for (int i = 0; i < min(size_t(5), s.size()); i++) {
            string tmp;
            auto it = s.begin();

            while (it - s.begin() <= i) {
                tmp += *it;

                ++it;
            }

            while (true) {
                int x = stoi(tmp);
                
                if (era[x]) {
                    m = max(m, x);
                }

                if (it == s.end()) {
                    break;
                }

                tmp.erase(tmp.begin());
                tmp += *it;
                ++it;
            }
        }

        cout << m << endl;
    }

    return 0;
}