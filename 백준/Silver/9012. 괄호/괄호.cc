//
// Created by woo-young Choi on 2022/08/14.
//

#include <iostream>
#include <queue>
#include <iterator>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;

    while (n--) {
        string s; cin >> s;

        queue<char> q;
        bool is_ended = false;

        for (const auto& x : s) {
            if (x == '(')
                q.push(x);
            else if (x == ')' && !q.empty())
                q.pop();
            else { cout << "NO\n"; is_ended = true; break; }
        }

        if (!is_ended) {
            if (q.empty()) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
