#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    string s; cin >> s;
    auto it1 = s.begin();
    auto it2 = s.begin();

    int ans = 0;
    bool found = false;

    while ((s.end() - it1) >= (2 * n + 1)) {
        if (found) {
            if (*(it2 + 1) != 'O') { it1 = it2 + 1; found = false; }
            else if (*(it2 + 2) != 'I') { it1 = it2 + 2; found = false; }
            else {
                ++ans;
                it2 += 2;
                it1 += 2;
            }
        }
        else {
            if (*it1 == 'I') {
                it2 = it1;
                bool is_IOI = true;

                for (int i = 0; i < n; ++i) {
                    if (*(it2 + 1) != 'O') { it1 = it2 + 1; is_IOI = false; break; }
                    if (*(it2 + 2) != 'I') { it1 = it2 + 2; is_IOI = false; break; }
                    else it2 += 2;
                }

                if (is_IOI) {
                    ++ans;
                    found = true;
                    it1 += 2;
                }
            }

            else ++it1;
        }
    }

    cout << ans;
}