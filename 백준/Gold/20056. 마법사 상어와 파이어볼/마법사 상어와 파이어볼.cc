//
// Created by 99woo on 2023-01-10.
//

#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;
using vii = vector<pii>;
using ll = long long;

#define endl '\n'
#define em emplace
#define emb emplace_back
#define all(x) x.begin(), x.end()
#define fastio iostream::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

ll ans = 0;

int n, m, k;

vector<pii> direction = {
        {-1, 0},
        {-1, 1},
        {0,  1},
        {1,  1},
        {1,  0},
        {1,  -1},
        {0,  -1},
        {-1, -1}};

struct Fireball {
    int x, y, mass, dir, speed;

    Fireball(int x, int y, int mass, int speed, int dir) : x(x), y(y), mass(mass), speed(speed), dir(dir) {}

    bool operator<(const Fireball &rhs) const {
        return x == rhs.x ? y < rhs.y : x < rhs.x;
    }
};

vector<Fireball> before_move, after_move;

void input() {
    cin >> n >> m >> k;

    int x, y, mass, speed, dir;
    while (m--) {
        cin >> x >> y >> mass >> speed >> dir;

        before_move.emb(x - 1, y - 1, mass, speed, dir); // x: row, y: column
    }
}

int fix_pos(int i) {
    if (i >= 0) return i % n;
    else {
        return (n + i % n) % n;
    }
}

void processing(int x, int y, int mass, int speed, int cnt, bool allSame) {
    mass /= 5;
    speed /= cnt;

    if (mass == 0) return;

    for (int i = 0; i < 8; i += 2) before_move.emb(x, y, mass, speed, i + !allSame);
}

void solve() {
    while (k--) {
        for (const auto &fire: before_move) {
            auto x = fix_pos(fire.x + fire.speed * direction[fire.dir].first);
            auto y = fix_pos(fire.y + fire.speed * direction[fire.dir].second);

            after_move.emb(x, y, fire.mass, fire.speed, fire.dir);
        }

        before_move.clear();
        sort(all(after_move));

        int nowx = -1, nowy = -1, smass = -1, sspeed = -1, cnt = -1, fir_dir = -1;
        bool allSame;

        for (const auto &fire: after_move) {
            if (nowy == fire.y && nowx == fire.x) {
                smass += fire.mass;
                sspeed += fire.speed;
                ++cnt;
                if ((fir_dir & 1) != (fire.dir & 1)) allSame = false;
                continue;
            }

            if (cnt == 1) before_move.emb(nowx, nowy, smass, sspeed, fir_dir);
            else processing(nowx, nowy, smass, sspeed, cnt, allSame);

            nowx = fire.x;
            nowy = fire.y;
            smass = fire.mass;
            sspeed = fire.speed;
            fir_dir = fire.dir;
            cnt = 1;
            allSame = true;
        }

        if (cnt == 1) before_move.emb(nowx, nowy, smass, sspeed, fir_dir);
        else processing(nowx, nowy, smass, sspeed, cnt, allSame);

        after_move.clear();
    }

    for (const auto &fire: before_move) ans += fire.mass;
}

void output() {
    cout << ans;
}

int main() {
    fastio

    input();
    solve();
    output();
}