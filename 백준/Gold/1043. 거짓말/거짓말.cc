#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

unordered_set<int> knowstruth; // 진실을 아는 사람들

vector<unordered_set<int>> connection; // 그래프

vector<vector<int>> party; // 파티 정보

int n, m; // 사람 수, 파티 수

void input() {
    cin >> n >> m;

    connection.resize(n + 1); // 그래프 크기 설정
    party.resize(m); // 파티 크기 설정

    int nokhts; // number of knowing her true story
    cin >> nokhts;

    int num;
    while (nokhts--) {
        cin >> num;
        knowstruth.emplace(num);
    }

    for (auto &party_data: party) {
        int invited_num;
        cin >> invited_num;

        party_data.resize(invited_num);

        for (auto &member: party_data) {
            cin >> member;
        }

        for (const auto &from: party_data) {
            for (const auto &to: party_data) {
                connection[from].emplace(to);
            }
        }
    }
}

void solve() {
    queue<int> q;

    for (const auto &x: knowstruth) {
        q.emplace(x);
    }

    int now;
    while (!q.empty()) {
        now = q.front();
        q.pop();

        for (const auto &x: connection[now]) {
            if (knowstruth.find(x) != knowstruth.end()) continue;

            knowstruth.emplace(x);
            q.emplace(x);
        }
    }

    int ans = 0;
    for (const auto &party_data: party) {
        if (all_of(party_data.begin(), party_data.end(), [=](int x) { return knowstruth.find(x) == knowstruth.end(); }))
            ++ans;
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    solve();
}
