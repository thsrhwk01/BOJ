//
// Created by woo-young Choi on 2022/08/27.
//

#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;

    unordered_map<int, string> num_map;
    unordered_map<string, int> name_map;

    for (int i = 1; i <= n; ++i) {
        string name;
        cin >> name;
        num_map[i] = name;
        name_map[name] = i;
    }

    while (m--) {
        string cmd;
        cin >> cmd;
        if (cmd[0] >= 48 && cmd[0] <= 57) {
            int tmp = stoi(cmd);
            cout << num_map[tmp] << '\n';
        } else {
            cout << name_map[cmd] << '\n';
        }
    }
}