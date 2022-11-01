//
// Created by woo-young Choi on 2022/10/31.
//

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define pii pair<int, int>
#define vii vector<pii>
#define ll long long

#define em emplace
#define emb emplace_back
#define range(x) x.begin(), x.end()
#define fastio iostream::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

array<bool, 1'000'001> checking;
string s1, s2;

void input() {
    cin >> s1 >> s2;
    fill(checking.begin(), checking.end(), true);
}

bool eraser(int &i) {
    int start = i;
    auto now2 = s2.begin() + 1;

    ++i;
    bool checker = [&] {
        vii ranges;
        
        while (now2 != s2.end()) {
            if (i >= s1.size()) return false;
            if (s1[i] == s2.front()) {
                ranges.emb(start, i);
                checker = eraser(i);
                start = i;
                if (!checker) return false;
            } else if (s1[i] == *now2) {
                ++i;
                ++now2;
                continue;
            } else return false;
        }
        
        for (auto x: ranges) {
            fill(checking.begin() + x.first, checking.begin() + x.second, false);
        }
        fill(checking.begin() + start, checking.begin() + i, false);

        return true;
    }();

    return checker;
}

void solve() {
    int i = 0;

    while (i < s1.size()) {
        if (s1[i] == s2.front()) {
            eraser(i);
        }
        else ++i;
    }
}

void output() {
    int i = 0;
    [&] {
        while (i < s1.size()) {
            if (checking[i]) return;
            ++i;
        }
        cout << "FRULA";
    }();

    while (i < s1.size()) {
        if (checking[i]) cout << s1[i];
        ++i;
    }
}

int main() {
    fastio

    input();
    solve();
    output();
}