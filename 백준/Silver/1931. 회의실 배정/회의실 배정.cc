#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int>& rhs, const pair<int, int>& lhs) {
    if (rhs.first == lhs.first) return rhs.second < lhs.second;
    else return rhs.first < lhs.first;
}

int main () {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n; cin >> n;
    if (n == 1) { cout << 1; return 0; }
    pair<int, int> mp[n];

    for (int i = 0; i < n; ++i) {
        cin >> mp[i].second >> mp[i].first;
    }

    sort(mp, mp + n, cmp);

    int cnt = 1;;
    auto now = mp[0];
    auto it = 1;

    while (it < n) {
        if (mp[it].second >= now.first) {
            ++cnt;
            now = mp[it];
        }
        ++it;
    }

    cout << cnt;
}