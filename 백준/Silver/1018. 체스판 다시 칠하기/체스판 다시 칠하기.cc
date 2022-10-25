#include <iostream>
using namespace std;

int main() {
	int n, m, ans = 64;
	cin >> n >> m;

	char board[n][m];
	for (int i = 0 ; i < n ; i++) cin >> board[i];

	for (int i = 0 ; i <= n-8 ; i++)
		for (int j = 0 ; j <= m-8 ; j++) {
			int temp = 0;
			for (int k = 0; k < 8 ; k++)
				for (int l = 0; l < 8 ; l++) temp += (board[i+k][j+l] == ((k+l)%2 ? 'B' : 'W'));
			ans = min(ans, min(temp, 64-temp));
		}

	cout << ans;
}