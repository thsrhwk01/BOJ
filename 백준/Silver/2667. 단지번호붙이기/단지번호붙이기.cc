#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ans;

int n;

void numbering(int** apt, int x, int y, int number) {
    ans[number]++;

    if (x-1 >= 0 && apt[x-1][y] == 1) { apt[x-1][y] = 0; numbering(apt, x-1, y, number); }
    if (y-1 >= 0 && apt[x][y-1] == 1) { apt[x][y-1] = 0; numbering(apt, x, y-1, number); }
    if (x+1 < n && apt[x+1][y] == 1) { apt[x+1][y] = 0; numbering(apt, x+1, y, number); }
    if (y+1 < n && apt[x][y+1] == 1) { apt[x][y+1] = 0; numbering(apt, x, y+1, number); }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;

    int** apt = new int * [n];

    for (int i = 0; i < n; ++i) {
        apt[i] = new int [n];
        string tmp; cin >> tmp;
        for (int j = 0; j < n; ++j) {
            apt[i][j] = tmp[j] - 48;
        }
    }

    int number = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (apt[i][j] == 1) {
                ans.emplace_back(0);
                apt[i][j] = 0;
                numbering(apt, i, j, number++);
            }
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for (const auto& x : ans) cout << x << '\n';
}