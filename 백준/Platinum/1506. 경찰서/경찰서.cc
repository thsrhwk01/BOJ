#include <bits/stdc++.h>

using namespace std;

using ll  = long long;
using vi  = vector<int>;
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

int ans, cityCount, ID, cityCost[101], cityParent[101];
bool cityFinished[101];
stack<int> stk;
vi cityEdge[101];
vvi citySCC;

void input() {
    cin >> cityCount;

    rep(i, 1, cityCount) cin >> cityCost[i];

    rep(i, 1, cityCount) {
        rep(j, 1, cityCount) {
            char roadExists;
            cin >> roadExists;

            if (roadExists == '1')
                cityEdge[i].emb(j);
        }
    }
}

int dfs(int thisCity) {
    cityParent[thisCity] = ++ID;
    stk.em(thisCity);

    int thisParent = cityParent[thisCity];

    for (auto nextCity : cityEdge[thisCity]) {
        if (cityParent[nextCity] == 0)
            thisParent = min(thisParent, dfs(nextCity));
        else if (!cityFinished[nextCity])
            thisParent = min(thisParent, cityParent[nextCity]);
    }

    if (thisParent == cityParent[thisCity]) {
        vi tempSCC;

        while (true) {
            auto childCity = stk.top();
            stk.pop();
            tempSCC.emb(childCity);
            cityFinished[childCity] = true;
            if (childCity == thisCity)
                break;
        }

        citySCC.emb(tempSCC);
    }

    return thisParent;
}

void solve() {
    rep(i, 1, cityCount) if (cityParent[i] == 0) dfs(i);
    for (const auto &scc : citySCC) {
        int minCost = 0x3f3f3f3f;
        for (auto city : scc) {
            minCost = min(minCost, cityCost[city]);
        }

        ans += minCost;
    }
}

void output() { cout << ans; }

int main() {
    fastio;

    input();
    solve();
    output();
}