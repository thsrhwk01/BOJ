#include <iostream>

using namespace std;

int main() {
	int n, a = 665;
	cin >> n;

	while (n) {
		a++;
		int tmp = a;
		while (tmp != 0) {
			if (tmp % 1000 == 666) {
				n--;
				break;
			} else tmp /= 10;
		}
	}

	cout << a;
}