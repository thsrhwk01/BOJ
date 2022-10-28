//
// Created by woo-young Choi on 2022/08/13.
//

#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> q;
    int n; cin >>n;

    for (int i = 1; i < n + 1; ++i) {
        q.push(i);
    }

    bool switcher = true;

    while(q.size() != 1) {
        if (switcher) {
            q.pop();
        }
        else {
            q.push(q.front());
            q.pop();
        }

        switcher = !switcher;
    }

    cout << q.front();
}