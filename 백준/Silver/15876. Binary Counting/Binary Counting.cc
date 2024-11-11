#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <stack>
#include <vector>

using namespace std;

#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    int cnt = 0, turn = 0, num = 1;
    stack<int> stk;
    stk.emplace(0);

    while (cnt < 5) {
        if (stk.empty()) {
            int tmp = num;
            while (tmp) {
                stk.emplace(tmp % 2);
                tmp /= 2;
            }

            num++;
        }

        int now = stk.top();
        stk.pop();

        if (turn == k - 1) {
            cnt++;
            
            cout << now << ' ';
        }

        turn++;
        turn %= n;
    }

    return 0;
}