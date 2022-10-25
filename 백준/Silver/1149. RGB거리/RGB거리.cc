#include <iostream>

using namespace std;

void input_and_solve() {
    int n;
    cin >> n;

    int r, g, b;
    cin >> r >> g >> b;
    int cases[3] = {r, g, b};

    int tr, tg, tb;
    while(--n) {
        cin >> r >> g >> b;
        tr = r + min(cases[1], cases[2]);
        tg = g + min(cases[0], cases[2]);
        tb = b + min(cases[0], cases[1]);

        cases[0] = tr;
        cases[1] = tg;
        cases[2] = tb;
    }

    cout << min(cases[0], min(cases[1], cases[2]));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input_and_solve();
}
