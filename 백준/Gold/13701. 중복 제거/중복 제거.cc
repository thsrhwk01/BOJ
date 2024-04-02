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

vector<bool> vec;

int main() {
    iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vec.resize(33554435);
    fill(all(vec), false);

    int n;

    while (cin >> n) {
        if (!vec[n]) cout << n << ' ';  
        vec[n] = true;
    }

    return 0;
}