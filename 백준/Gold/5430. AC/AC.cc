#include <iostream>
#include <deque>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;

    while (n--) {
        string cmds; cin >> cmds;
        int number_size; cin >> number_size;
        string number_str; cin >> number_str;
        deque<int> numbers;

        int tmp = 0;
        auto it = number_str.begin();
        ++it;

        while (numbers.size() < number_size) {
            if (*it == ',' || *it == ']') {
                numbers.emplace_back(tmp);
                tmp = 0;
                ++it;
            } else {
                tmp = tmp * 10 + (*it - 48);
                ++it;
            }
        }

        bool is_reversed = false;
        bool error = false;

        for (const char& cmd : cmds) {
            if (cmd == 'R') is_reversed = !is_reversed;
            else {
                if (numbers.empty()) { cout << "error" << '\n'; error = true; break; }
                else if (!is_reversed) {
                    numbers.pop_front();
                }
                else {
                    numbers.pop_back();
                }
            }
        }


        if (!error) {
            cout << '[';
            ostream_iterator<int> os(cout, ",");
            if (!numbers.empty()) {
                if (!is_reversed) {
                    copy(numbers.begin(), numbers.end() - 1, os);
                    cout << numbers.back();
                } else {
                    copy(numbers.rbegin(), numbers.rend() - 1, os);
                    cout << numbers.front();
                }
            }
            cout << ']' << '\n';
        }
    }
}