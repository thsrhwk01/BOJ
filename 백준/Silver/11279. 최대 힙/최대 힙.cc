#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    priority_queue<int> q;

    int tmp;

    while(n--) {
        cin >> tmp;
        if (tmp == 0) {
            if (q.empty()) cout << 0 << '\n';
            else {
                cout << q.top() << '\n';
                q.pop();
            }
        }
        else q.emplace(tmp);
    }
}