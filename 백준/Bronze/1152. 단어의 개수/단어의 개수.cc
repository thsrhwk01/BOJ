#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    string str;
    int cnt = 0;

    while (cin >> str) {
        ++cnt;
    }

    cout << cnt;
}