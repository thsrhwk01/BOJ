//
// Created by woo-young Choi on 2022/08/27.
//

#include <iostream>
#include <queue>

using namespace std;

bool visited[100'001] = {false , };

int start, last;

unsigned int finding() {
    int time = 0;
    queue<int> q, nq;
    q.push(start);

    while (true) {
        auto now = q.front();
        q.pop();

        visited[now] = true;
        if (now == last) return time;

        if (now - 1 >= 0 && !visited[now - 1]) nq.push(now - 1);
        if (now + 1 <= 100'000 && !visited[now + 1]) nq.push(now + 1);
        if (now * 2 <= 100'000 && !visited[now * 2]) nq.push(now * 2);

        if (q.empty()) {
            swap(q, nq);
            ++time;
        }
    }
}

int main() {
    cin >> start >> last;
    cout << finding();
}