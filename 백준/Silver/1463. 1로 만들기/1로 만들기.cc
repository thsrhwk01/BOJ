#include <iostream>

using namespace std;

void cal_cnt(int* un, int n) {
    if (n % 6 == 0) un[n] = min(un[n / 3], min(un[n / 2], un[n - 1])) + 1;
    else if (n % 3 == 0) un[n] = min(un[n / 3], un[n - 1]) + 1;
    else if (n % 2 == 0) un[n] = min(un[n / 2], un[n - 1]) + 1;
    else un[n] = un[n - 1] + 1;
}

int main() {
    int n; cin >> n;
    int un[n + 1];
    un[1] = 0;

    for (int i = 2; i <= n; ++i) cal_cnt(un, i);

    cout << un[n];
}