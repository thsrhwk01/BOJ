#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <tuple> 
#include <set>

using namespace std;

using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    set<string> s;
    map<string, int> p2i;
    vvi cnt(15, vi(50005));
    int idx = 0;

    while (n--) {
        string name, place;
        int from, to;

        cin >> name >> place >> from >> to;

        if (s.contains(name)) {
            continue;
        }

        s.emplace(name);

        if (!p2i.contains(place)) {
            p2i[place] = idx++;
        } 

        int p = p2i[place];
        cnt[p][from]++;
        cnt[p][to]--;
    }

    for (int i = 0; i < idx; i++) {
        for (int j = 1; j < 50003; j++) {
            cnt[i][j] += cnt[i][j - 1];
        }
    }

    // cnt, place, from, to
    set<tuple<int, string, int, int>> ans;

    for (const auto &[place, idx] : p2i) {
        int from = 0;

        for (int i = 0; i < 50003; i++) {
            if (cnt[idx][i] != cnt[idx][from]) {
               ans.emplace(-cnt[idx][from], place, from, i);
               from = i; 
            }
        }
    }

    auto [tmp, place, from, to] = *ans.begin();
    cout << place << ' ' << from << ' ' << to;
}