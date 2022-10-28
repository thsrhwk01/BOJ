#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct cmp {
    bool operator() (const int& rhs, const int& lhs) const {
        return rhs > lhs;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    priority_queue<int, vector<int>, cmp> pq;

    int n; cin >> n;

    while (n--) {
        int cmd; cin >> cmd;
        if (cmd == 0) {
            if (pq.empty()) cout << 0 << '\n';
            else { cout << pq.top() << '\n'; pq.pop(); }
        }
        else
            pq.emplace(cmd);
    }
}