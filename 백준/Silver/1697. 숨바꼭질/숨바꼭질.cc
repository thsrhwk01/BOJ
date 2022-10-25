#include <iostream>
#include <queue>

using namespace std;

bool visited[100'001] = {false , };

unsigned int finding(const int& start, const int& end) {
    queue<pair<int, unsigned int>> q;
    q.push({start, 0});
    while (true) {
        auto now = q.front();
        q.pop();

        visited[now.first] = true;
        if (now.first == end) return now.second;

        if (now.first - 1 >= 0 && !visited[now.first - 1]) q.push({now.first - 1, now.second + 1});
        if (now.first + 1 <= 100'000 && !visited[now.first + 1]) q.push({now.first + 1, now.second + 1});
        if (now.first * 2 <= 100'000 && !visited[now.first * 2]) q.push({now.first * 2, now.second + 1});
    }
}

int main() {
    int start, end; cin >> start >> end;
    cout << finding(start, end);;
}