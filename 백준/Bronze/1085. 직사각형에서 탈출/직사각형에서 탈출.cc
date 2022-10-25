#include <iostream>

using namespace std;

int main() {
	int x, y, w, h, a, b;

	cin >> x >> y >> w >> h;

	a = x < w - x ? x : w - x;
	b = y < h - y ? y : h - y;

	cout << (a < b ? a : b);

	return 0;
}