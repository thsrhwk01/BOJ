#include <iostream>

using namespace std;

long long ans;

long long pow(const int &a, int b, const int &c) {
    if (b == 1) return a % c;

    long long tmp = pow(a, b / 2, c);
    tmp = (tmp * tmp) % c;

    if (b % 2 != 0) return (tmp * a) % c;
    return tmp;
}

void input() {
    int a, b, c;
    cin >> a >> b >> c;

    ans = pow(a, b, c);
}

void output() {
    cout << ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    output();
}