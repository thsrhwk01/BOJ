#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

long long score(vector<int>& scores, unordered_map<int, long long>& m, int i) {
    if (m.find(i) != m.end()) return m[i];
    else {
        m[i] = score(scores, m, i - 2);
        m[i] = m[i] > score(scores, m, i - 3) + scores[i - 1] ?
                m[i] : score(scores, m, i - 3) + scores[i - 1];
        m[i] += scores[i];
    }
    return m[i];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    vector<int> scores;
    scores.push_back(0);

    while (n--) {
        int tmp; cin >> tmp;
        scores.push_back(tmp);
    }

    if (scores.size() <= 3) {
        long long sum = 0;
        for (const auto& x : scores) sum += x;
        cout << sum;
        return 0;
    }

    unordered_map<int, long long> best_scores;
    best_scores[0] = 0; best_scores[1] = scores[1]; best_scores[2] = scores[1] + scores[2];

    auto res = score(scores, best_scores, scores.size() - 1);

    cout << res;
}