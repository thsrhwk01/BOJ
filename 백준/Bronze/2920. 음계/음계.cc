#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a;

	if (a == 1) {
		while(cin >> b) {
			if (a > b) {
				cout << "mixed";
				return 0;
			}
			a = b;
		}
		cout << "ascending";
	} else if (a == 8) {
		while(cin >> b) {
			if (a < b) {
				cout << "mixed";
				return 0;
			}
			a = b;
		}
		cout << "descending";
	} else cout << "mixed";

	return 0;
}