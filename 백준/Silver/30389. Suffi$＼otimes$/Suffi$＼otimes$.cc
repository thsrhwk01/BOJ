#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

#define endl '\n'
#define em emplace
#define emb emplace_back
#define all(x) x.begin(), x.end()
#define rep(i, from, to) for (int i = from; i <= to; ++i)
#define fastio                                                                 \
    iostream::sync_with_stdio(false);                                          \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);

int main() {
    fastio;

    map<string, int> mp;

    int n;
    cin >> n;

    rep(i, 1, n) {
        string s;
        cin >> s;

        for (int j = 0; j < s.size(); ++j) {
            mp[s.substr(j)]++;
        }
    }

    int ans = 0;
    for (const auto &p : mp) {
        ans += (p.second & 1);
    }

    cout << ans;
}