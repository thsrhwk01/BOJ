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

    const size_t sz = 51;

    int n, m;
    cin >> n >> m;

    vector<bitset<sz>> guitars(n);

    for (auto &guitar : guitars) {
        string trash, songDatas;

        cin >> trash >> songDatas;

        for (int i = 0; i < m; ++i) {
            guitar[i] = (songDatas[i] == 'Y' ? true : false);
        }
    }

    int minimumGuitarCount = 0x3f3f3f3f, maximumSongCount = 0;

    auto backTracking = [&](auto &&self, int idx, int cnt,
                            bitset<sz> playable) -> void {
        if (idx != -1) {
            playable |= guitars[idx];
        }

        if (playable.count() > maximumSongCount) {
            maximumSongCount = playable.count();
            minimumGuitarCount = cnt;
        } else if (playable.count() == maximumSongCount) {
            minimumGuitarCount = min(minimumGuitarCount, cnt);
        }

        for (int i = idx + 1; i < n; ++i) {
            self(self, i, cnt + 1, playable);
        }
    };

    backTracking(backTracking, -1, 0, bitset<sz>());

    cout << (maximumSongCount == 0 ? -1 : minimumGuitarCount);

    return 0;
}