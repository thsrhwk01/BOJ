#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

bool visited[10000];

string searching(int start, int goal) {
    fill_n(visited, 10000, false);
    visited[start] = true;
    queue<pair<int, string>> q;
    if ((start * 2 % 10000) == goal) return "D";
    else {
        visited[start * 2 % 10000] = true;
        q.emplace(start * 2 % 10000, "D");
    }
    if (!visited[(start > 0 ? start - 1 : 9999)]) {
        if ((start > 0 ? start - 1 : 9999) == goal) return "S";
        else {
            q.emplace((start > 0 ? start - 1 : 9999), "S");
            visited[(start > 0 ? start - 1 : 9999)] = true;
        }
    }
    if (!visited[((start % 1000) * 10 + (start / 1000))]) {
        if (((start % 1000) * 10 + (start / 1000)) == goal) return "L";
        else {
            visited[(start % 1000) * 10 + (start / 1000)] = true;
            q.emplace((start % 1000) * 10 + (start / 1000), "L");
        }
    }
    if (!visited[(start % 10) * 1000 + (start / 10)]) {
        if (((start % 10) * 1000 + (start / 10)) == goal) return "R";
        else {
            visited[(start % 10) * 1000 + (start / 10)] = true;
            q.emplace((start % 10) * 1000 + (start / 10), "R");
        }
    }

    while (!q.empty()) {
        int now_num = q.front().first;
        string now_cmd = q.front().second;
        q.pop();

        if (!visited[now_num * 2 % 10000]) {
            if ((now_num * 2 % 10000) == goal) return now_cmd + "D";
            else {
                visited[now_num * 2 % 10000] = true;
                q.emplace(now_num * 2 % 10000, now_cmd + "D");
            }
        }
        if (!visited[(now_num > 0 ? now_num - 1 : 9999)]) {
            if ((now_num > 0 ? now_num - 1 : 9999) == goal) return now_cmd + "S";
            else {
                q.emplace((now_num > 0 ? now_num - 1 : 9999), now_cmd + "S");
                visited[(now_num > 0 ? now_num - 1 : 9999)] = true;
            }
        }
        if (!visited[((now_num % 1000) * 10 + (now_num / 1000))]) {
            if (((now_num % 1000) * 10 + (now_num / 1000)) == goal) return now_cmd + "L";
            else {
                visited[(now_num % 1000) * 10 + (now_num / 1000)] = true;
                q.emplace((now_num % 1000) * 10 + (now_num / 1000), now_cmd + "L");
            }
        }
        if (!visited[(now_num % 10) * 1000 + (now_num / 10)]) {
            if (((now_num % 10) * 1000 + (now_num / 10)) == goal) return now_cmd + "R";
            else {
                visited[(now_num % 10) * 1000 + (now_num / 10)] = true;
                q.emplace((now_num % 10) * 1000 + (now_num / 10), now_cmd + "R");
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int test_num; cin >> test_num;

    while(test_num--) {
        int start, goal; cin >> start >> goal;
        string ans = searching(start, goal);

        cout << ans << '\n';
    }
}