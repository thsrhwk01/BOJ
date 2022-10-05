#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, pair<long, long>> un;

pair<long, long> fibonacci (int n) {
    if (un.find(n) != un.end()) return un[n];
    else {
        auto before = fibonacci(n - 1), before_before = fibonacci(n - 2);
        un[n] = make_pair(before.first + before_before.first,
                          before.second + before_before.second);

        return un[n];
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n; cin >> n;

    un[-2] = {0, 0};
    un[-1] = {0, 0};
    un[0] = {1, 0};
    un[1] = {0, 1};

    while (n--) {
        int tmp; cin >> tmp;
        auto tmp_fibo = fibonacci(tmp);
        cout << tmp_fibo.first << ' ' << tmp_fibo.second <<'\n';
    }
}