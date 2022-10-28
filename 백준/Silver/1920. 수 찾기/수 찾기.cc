#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> vec(n);
    for_each(vec.begin(), vec.end(), [] (int& in) { cin >> in; });
    sort(vec.begin(), vec.end());

    int m; cin >> m;
    while (m--) {
        int searching; cin >> searching;
        cout << binary_search(vec.begin(), vec.end(), searching) << '\n';
    }
}