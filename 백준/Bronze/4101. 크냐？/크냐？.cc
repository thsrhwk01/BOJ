#include <iostream>

using namespace std;

int main() {
    int i, j;
    
    while (cin >> i >> j && (i != 0 && j != 0)) 
        cout << (i > j ? "Yes" : "No") << '\n';
}