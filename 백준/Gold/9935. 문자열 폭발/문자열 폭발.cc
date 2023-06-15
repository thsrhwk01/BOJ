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

stack<char> stk;
string orig, bomb, ans;

void input() { cin >> orig >> bomb; }

void solve() {
    rep(i, 0, orig.size() - 1) {
        ans += orig[i];

        if (ans.back() == bomb.back()) {

            [&] {
                while (true) {
                    if (ans.size() < bomb.size())
                        return;

                    int j = ans.size() - 1;
                    int k = bomb.size() - 1;

                    while (k >= 0)
                        if (bomb[k--] != ans[j--])
                            return;

                    k = bomb.size();
                    while (k--)
                        ans.pop_back();
                }
            }();
        }
    }
}

void output() { cout << (ans.empty() ? "FRULA" : ans); }

int main() {
    fastio;

    input();
    solve();
    output();
}