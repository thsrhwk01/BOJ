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

void solve(int n) {
    vector<pair<int, string>> vec;

    rep(i, 1, n) {
        string name;
        double sz;

        cin >> name >> sz;

        vec.emb(sz * 100, name);
    }


    sort(all(vec), [] (const pair<int, string> &lhs, const pair<int, string> &rhs) {
        return lhs.first > rhs.first;
    });

    for (const auto &p : vec) {
        if (p.first < vec[0].first) {
            break;
        }

        cout << p.second << ' ';
    }

    cout << endl;
    return;
}

int main() {
    iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;

    while (true) {
        cin >> n;

        if (n == 0) {
            break;
        }

        solve(n);
    }

    return 0;
}