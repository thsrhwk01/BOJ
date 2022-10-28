#include <iostream>

using namespace std;

int main() {
    int i, j;
    while (cin >> i >> j && (i != 0 && j != 0)) {
        if (i > j) cout << "Yes\n";
        else cout << "No\n";
    }
}