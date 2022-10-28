//
// Created by woo-young Choi on 2022/08/14.
//

#include <iostream>
#include <vector>

using namespace std;

int main () {
    int n, m; cin >> n >> m;
    int record = -1;
    vector<int> cards;
    while (n--) {
        int tmp; cin >> tmp;
        if (tmp <= m) cards.push_back(tmp);
    }

    for (int i = 0; i < cards.size() - 2; ++i) {
        for (int j = i + 1; j < cards.size() - 1; ++j) {
            for (int k = j + 1; k < cards.size(); ++k) {
                if (cards[i] + cards[j] + cards[k] <= m and record < cards[i] + cards[j] + cards[k] ) {
                    record = cards[i] + cards[j] + cards[k];
                    if (record == m) { cout << record; return 0; }
                }
            }
        }
    }

    cout << record;
}