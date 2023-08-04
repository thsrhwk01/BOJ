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

string a, b;
bool ans;

void solve() {
    ans = false;

    int i = 0;
    for (auto &ch : b) {
        if (a[i] == ch)
            ++i;

        if (i == a.size()) {
            ans = true;
            break;
        }
    }
}

void output() { cout << (ans ? "Yes" : "No") << endl; }

int main() {
    fastio;

    while (cin >> a) {
        cin >> b;
        solve();
        output();
    }
}