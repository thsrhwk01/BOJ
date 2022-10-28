#include <iostream>

using namespace std;

int main() {
    int kg; cin >> kg;
    if (kg % 5 == 0) cout << kg / 5;
    else if (kg % 3 == 0 || (kg > 5 && (kg - 5) % 3 == 0) || (kg > 10 && (kg - 10) % 3 == 0)) {
        int cnt = 0;
        while (kg % 5 != 0) {
            kg -= 3;
            ++cnt;
        }

        cout << cnt + kg / 5;
    } else cout << -1;
}