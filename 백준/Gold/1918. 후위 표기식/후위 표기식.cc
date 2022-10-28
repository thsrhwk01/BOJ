#include <iostream>
#include <stack>

using namespace std;

string notation, ans;

void input() {
    cin >> notation;
}

void solve() {
    stack<char> stk;

    for (const auto &ch: notation) {
        if (ch >= 'A' && ch <= 'Z') ans += ch;
        else {

            if (ch == '(') stk.push(ch);

            else if (ch == '*' || ch == '/') {
                while (!stk.empty() && (stk.top() == '*' || stk.top() == '/')) {
                    ans += stk.top();
                    stk.pop();
                }

                stk.push(ch);
            } else if (ch == '+' || ch == '-') {
                while (!stk.empty() && stk.top() != '(') {
                    ans += stk.top();
                    stk.pop();
                }
                stk.push(ch);
            } else if (ch == ')') {
                while (!stk.empty() && stk.top() != '(') {
                    ans += stk.top();
                    stk.pop();
                }
                stk.pop();
            }
        }
    }

    while (!stk.empty()) {
        ans += stk.top();
        stk.pop();
    }
}

void output() {
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    solve();
    output();
}
