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
#define fastio                        \
    iostream::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

int main() {
    fastio;

    int n;
    cin >> n;

    vector<ll> arr(n);
    map<ll, int> mp;
    for (auto &i : arr) {
        cin >> i;
        mp[i]++;
    }

    int ans = 0;

    for (int i = 0; i < n; ++i) {
        mp[arr[i]]--;
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            mp[arr[j]]--;

            auto finding = arr[i] - arr[j];
            bool found = false;

            if (mp.contains(finding) and mp[finding] > 0) {
                found = true;
            }

            mp[arr[j]]++;

            if (found) {
                ++ans;
                break;
            }
        }

        mp[arr[i]]++;
    }

    cout << ans;
}