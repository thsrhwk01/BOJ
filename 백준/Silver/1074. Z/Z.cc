#include <iostream>
#include <cmath>

using namespace std;

int beginning[2][2] = {{0, 2}, {1, 3}};

double re(int x, int y) {
    if (x <= 1 && y <= 1) return beginning[x][y];
    int n = 0;
    while (max(x, y) >= pow(2, n + 1)) ++n;
    double asdf = pow(2, n);
    if (x >= asdf && y >= asdf) return pow(asdf, 2) * 3 + re(x - asdf, y -asdf);
    else if (x >= pow(2, n)) return pow(asdf, 2) + re(x - asdf, y);
    else return pow(asdf, 2) * 2 + re(x, y - asdf);
}

int main() {
    int n, r, c; cin >> n >> r >> c;
    cout.precision(0); cout << fixed;
    cout << re(c, r);
}