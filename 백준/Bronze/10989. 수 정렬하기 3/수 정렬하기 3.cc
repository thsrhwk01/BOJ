#include <iostream>
#include <map>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;

    map<int, int> mp;
    while (n--) {
        int tmp; cin >> tmp;
        mp[tmp]++;
    }

    ostream_iterator<int> os(cout, "\n");
    for (const auto& x : mp) {
        fill_n(os, x.second, x.first);
    }
}