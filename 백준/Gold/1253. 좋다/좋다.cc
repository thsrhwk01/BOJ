#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using tiii = tuple<int, int, int>;
using viii = vector<tiii>;

#define endl '\n'
#define em emplace
#define emb emplace_back
#define all(x) x.begin(), x.end()
#define rep(i, from, to) for (int i = from; i <= to; ++i)

int main() {
    iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> arr(n);
    for (auto &i : arr) {
        cin >> i;
    }
    sort(all(arr));

    int ans = 0;

    for (int i = 0; i < n; ++i) {
        auto checker = arr[i];
        int l = 0, r = n - 1;

        bool isAble = false;
        while (l < r) {
            auto sum = arr[l] + arr[r];

            if (l == i) {
                ++l;
            } else if (r == i) {
                --r;
            } else if (sum == checker) {
                isAble = true;
                break;
            } else if (sum > checker) {
                --r;
            } else {
                ++l;
            }
        }

        if (isAble) {
            ++ans;
        }
    }

    cout << ans;
}