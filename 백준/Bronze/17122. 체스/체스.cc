#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using tiii = tuple<int, int, int>;
using viii = vector<tiii>;

bool board[70];

void solve() {
    string tmp;
    cin >> tmp;

    int a = 0;
    a += tmp[0] - 'A' + 1;
    a += (tmp[1] - '0' - 1) * 8;

    int b;
    cin >> b;

    cout << (board[a] == board[b] ? "YES" : "NO") << endl;  
}

int main() {
    iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 0; i < 8; i++) {
        int row = i * 8;

        bool isBlack = (i % 2 == 0 ? true : false);

        for (int j = 1; j < 9; j++) {
            board[row + j] = isBlack;

            isBlack = !isBlack;
        }
    }

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}