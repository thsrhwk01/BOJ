#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, b, v; cin >> a >> b >> v;

    double day = double(v - b) / double(a - b);
    day = ceil(day);

    cout << fixed; cout.precision(0);
    cout << day;
}