#include <iostream>
#include <list>
#include <queue>

using namespace std;

#define endl '\n'

bool isWin(const list<int> &ls) {
    int a = 0, b = 0;

    auto it = ls.begin();

    while (it != ls.end()) {
        auto x = *it;
        ++it;
        auto y = *it;
        ++it;

        if (x == y) {
            continue;
        }

        if (x > y) {
            ++a;
        } else {
            ++b;
        }
    }

    return a > b;
}

int main() {
    int n;
    cin >> n;

    list<int> oriLs;

    oriLs.resize(2 * n);

    int ans = 0x7f7f7f7f;

    for (auto &&i : oriLs) {
        char c;
        cin >> c;

        i = (c == 'O' ? 1 : 0);
    }

    queue<pair<list<int>, int>> q;
    q.emplace(oriLs, 0);

    while (!q.empty()) {
        auto [ls, cnt] = q.front();
        q.pop();

        if (isWin(ls)) {
            ans = cnt;

            break;
        }

        for (int i = 1; i < 2 * n; i++) {
            auto tls = ls;
            auto it = tls.begin();
            advance(it, i);

            auto tmp = *it;
            tls.erase(it);
            tls.emplace_front(tmp);

            q.emplace(tls, cnt + 1);
        }
    }

    cout << ans;
}