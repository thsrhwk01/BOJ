#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

#define endl '\n'

vector<string> nums = {"ZERO", "ONE", "TWO",   "THREE", "FOUR",
                       "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

bool found;
vector<int> ans;
multiset<char> ms;

void backtracking(int x) {
    string num = nums[x];

    for (int i = 0; i < num.size(); i++) {
        auto it = find(ms.begin(), ms.end(), num[i]);
        if (it != ms.end()) {
            ms.erase(it);
        } else {
            for (int j = 0; j < i; j++) {
                ms.emplace(num[j]);
            }

            return;
        }
    }
    ans.emplace_back(x);

    if (ms.empty()) {
        found = true;

        return;
    }

    for (int i = 0; i < 10; i++) {
        backtracking(i);

        if (found) {
            return;
        }
    }

    ans.pop_back();
    for (auto c : num) {
        ms.emplace(c);
    }

    return;
}

void solve(int tcNum) {
    found = false;
    ans.clear();
    ms.clear();

    string s;
    cin >> s;

    for (auto c : s) {
        ms.emplace(c);
    }

    for (int i = 0; i < 10; i++) {
        backtracking(i);
        
        if (found) {
            break;
        }
    }

    cout << "Case #" << tcNum + 1 << ": ";
    for (auto i : ans) {
        cout << i;
    }
    cout << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        solve(i);
    }

    return 0;
}