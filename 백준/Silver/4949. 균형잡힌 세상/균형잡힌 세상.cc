#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    string str;
    while (getline(cin, str) && str != ".") {
        stack<char> stk;
        bool printed = false;
        for (const auto& ch : str) {
            if (ch == '(' || ch == '[') {
                stk.push(ch);
            }
            else if (ch == ')') {
                if (!stk.empty() && stk.top() == '(') stk.pop();
                else { cout << "no" << '\n'; printed = true; break; }
            }
            else if (ch == ']') {
                if (!stk.empty() && stk.top() == '[') stk.pop();
                else { cout << "no" << '\n'; printed = true; break; }
            }
        }
        if (!printed && stk.empty()) cout << "yes" << '\n';
        else if (!printed) cout << "no" << '\n';
    }
}
