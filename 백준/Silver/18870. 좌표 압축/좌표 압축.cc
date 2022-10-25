#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> vec(n);
    vector<int> ans(n);

    for (int i = 0; i < n; ++i) {
        cin >> vec[i].first;
        vec[i].second = i;
    }

    sort(vec.begin(), vec.end());

    int cnt = 0;
    auto it = vec.begin();
    ans[it++->second] = cnt;
    while (it != vec.end()) {
        if (it->first != prev(it)->first) ++cnt;
        ans[(it++)->second] = cnt;
    }

    ostream_iterator<int> os(cout, " ");
    copy(ans.begin(), ans.end(), os);
}
