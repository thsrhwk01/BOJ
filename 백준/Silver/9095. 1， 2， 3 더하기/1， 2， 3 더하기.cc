#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> factorial_saving;

int factorial(int n) {
    if (factorial_saving.find(n) != factorial_saving.end()) return factorial_saving[n];
    if (n <= 1) return 1;

    factorial_saving[n] = n * factorial(n - 1);
    return factorial_saving[n];
}

int main() {
    int T; cin >> T;
    while (T--) {
        int sum = 0, n; cin >> n;

        for (int i = 0; i <= n / 3; ++i) {
            for (int j = 0; j <= (n - (3 * i)) / 2; ++j) {
                int number_num = i + j + (n - 3 * i - 2 * j);
                sum += factorial(number_num) / factorial(i) / factorial(j) / factorial(n - 3 * i - 2 * j);
            }
        }

        cout << sum << '\n';
    }
}