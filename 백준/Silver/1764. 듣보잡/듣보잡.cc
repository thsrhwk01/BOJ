#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    unordered_set<string> not_listened;
    set<string> answer;

    int listen, look; cin >> listen >> look;

    while (listen--) {
        string name; cin >> name;
        not_listened.emplace(name);
    }

    while (look--) {
        string name; cin >> name;
        if (not_listened.find(name) != not_listened.end()) answer.emplace(name);
    }

    cout << answer.size() << '\n';
    for (const auto& name : answer) cout << name << '\n';
}