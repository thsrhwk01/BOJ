//
// Created by woo-young Choi on 2022/10/23.
//

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define fastio iostream::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

map<int, int> for_sale;
bool checker[20'000'001];

vector<ll> highest;

int n, gap;

void input() {
    cin >> n >> gap;

    int height, value;
    while (n--) {
        cin >> height >> value;
        checker[height] = true;

        for_sale[height] = max(for_sale[height], value);
    }
}

void solve() {
    int range = for_sale.rbegin()->first - for_sale.begin()->first + 1;
    highest.resize(range);

    int lowest = for_sale.begin()->first;

    highest[0] = for_sale[lowest];

    for (int i = 1; i < range; ++i) {
        highest[i] = highest[i-1];
        if (i < gap) {
            if (checker[i + lowest] && for_sale[i + lowest] > highest[i]) highest[i] = for_sale[i + lowest];
        }
        else {
            if (checker[i + lowest] && for_sale[i + lowest] + highest[i - gap] > highest[i])
                highest[i] = for_sale[i + lowest] + highest[i - gap];
        }

        //cout << highest[i] << ' ';
    }
}

void output() {
    cout << *highest.rbegin();
}

int main() {
    fastio

    input();
    solve();
    output();
}
