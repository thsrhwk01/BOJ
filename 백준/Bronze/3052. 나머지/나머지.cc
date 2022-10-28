#include <iostream>
#include <vector>
using namespace std;

int main() {
	int rem[42] = {0};
	int num, howmuch = 0;

	while(cin >> num) {
		if (!rem[num%42]) {
			howmuch++;
			rem[num%42] = 1;
		}
	}

	cout << howmuch;

	return 0;
}