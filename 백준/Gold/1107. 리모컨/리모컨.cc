#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int channel, best, n; cin >> channel >> n;
    best = max(channel, 100) - min(channel, 100);
    vector<int> allowed_nums({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    while (n--) {
        int broken_num; cin >>broken_num;
        allowed_nums.erase(find(allowed_nums.begin(), allowed_nums.end(), broken_num));
    }

    int now, jari;
    for (const auto & n : allowed_nums) {
        
        best = min(best, (max(n, channel) - min(n, channel) + 1));
    }
    for (const auto& m : allowed_nums) {
        for (const auto & n : allowed_nums) {
            if (m > 0) jari = 2;
            else jari = 1;
            now = m * 10 + n;
            best = min(best, (max(now, channel) - min(now, channel) + jari));
        }
    }

    for (const auto& l : allowed_nums) {
        for (const auto& m : allowed_nums) {
            for (const auto & n : allowed_nums) {
                if (l > 0) jari = 3;
                else if (m > 0) jari = 2;
                else jari = 1;
                now = l * 100 + m * 10 + n;
                best = min(best, (max(now, channel) - min(now, channel) + jari));
            }
        }
    }
    for (const auto& k : allowed_nums) {
        for (const auto& l : allowed_nums) {
            for (const auto& m : allowed_nums) {
                for (const auto & n : allowed_nums) {
                    if (k > 0) jari = 4;
                    else if (l > 0) jari = 3;
                    else if (m > 0) jari = 2;
                    else jari = 1;
                    now = k * 1000 + l * 100 + m * 10 + n;
                    best = min(best, (max(now, channel) - min(now, channel) + jari));
                }
            }
        }
    }
    for (const auto& j : allowed_nums) {
        for (const auto& k : allowed_nums) {
            for (const auto& l : allowed_nums) {
                for (const auto& m : allowed_nums) {
                    for (const auto & n : allowed_nums) {
                        if (j > 0) jari = 5;
                        else if (k > 0) jari = 4;
                        else if (l > 0) jari = 3;
                        else if (m > 0) jari = 2;
                        else jari = 1;
                        now = j * 10000 + k * 1000 + l * 100 + m * 10 + n;
                        best = min(best, (max(now, channel) - min(now, channel) + jari));
                    }
                }
            }
        }
    }

    for (const auto& i : allowed_nums) {
        for (const auto& j : allowed_nums) {
            for (const auto& k : allowed_nums) {
                for (const auto& l : allowed_nums) {
                    for (const auto& m : allowed_nums) {
                        for (const auto & n : allowed_nums) {
                            if (i > 0) jari = 6;
                            else if (j > 0) jari = 5;
                            else if (k > 0) jari = 4;
                            else if (l > 0) jari = 3;
                            else if (m > 0) jari = 2;
                            else jari = 1;
                            now = i * 100000 + j * 10000 + k * 1000 + l * 100 + m * 10 + n;
                            best = min(best, (max(now, channel) - min(now, channel) + jari));
                        }
                    }
                }
            }
        }
    }

    cout << best;
}