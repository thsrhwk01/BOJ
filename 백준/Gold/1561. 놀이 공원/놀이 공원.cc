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
#define fastio                        \
    iostream::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

int times[31];
vi rides;

int n, m, ans;

void input()
{
    cin >> n >> m;

    int t;
    rep(i, 1, m)
    {
        cin >> t;

        times[t]++;
        rides.emb(t);
    }
}

void solve()
{
    ll s = 0, e = 60000000100;

    while (s < e)
    {
        ll cnt = 0, mid = (s + e) / 2;

        rep(i, 1, 30)
            cnt += times[i] * (mid / i + 1);

        if (cnt < n)
            s = mid + 1;
        else
            e = mid;
    }

    ll cnt = 0;
    if (s > 0)
        rep(i, 1, 30)
            cnt += times[i] * ((s - 1) / i + 1);

    rep(i, 0, rides.size() - 1)
    {
        if (s % rides[i] == 0)
            ++cnt;

        if (cnt == n)
        {
            ans = i + 1;
            return;
        }
    }
}

void output()
{
    cout << ans;
}

int main()
{

    input();
    solve();
    output();
}