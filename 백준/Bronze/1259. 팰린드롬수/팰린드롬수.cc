#include <iostream>
#include <string>

using namespace std;

int main() {
	int n, y;
	while (1) {
		y = 0;
		cin >> n;

		if (n == 0)
			break;

		string a = to_string(n);

		for (int i = 0 ; i < a.length()/2 ; i++) {
			if (a[i] != a[a.length()-i-1]) {
				y = 1;
				break;
			}
		}

		if (y == 0)
			cout << "yes\n";
		else
			cout << "no\n";
	}
}