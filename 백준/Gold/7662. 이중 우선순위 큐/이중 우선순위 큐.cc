#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int test_num; cin >> test_num;

    while (test_num--) {
        multiset<int, greater<>> pq;
        int cmd_num; cin >> cmd_num;
        char cmd;
        int n;

        while (cmd_num--) {
            cin >> cmd >> n;
            if (cmd == 'I') {
                pq.emplace(n);
            }
            else if (!pq.empty()) {
                if (n == 1)
                    pq.erase(pq.begin());
                else
                    pq.erase(prev(pq.end()));
            }
        }

        if (pq.empty()) cout << "EMPTY" << '\n';
        else cout << *pq.begin() << ' ' << *prev(pq.end()) << '\n';
    }
}