#include <iostream>
#include <vector>

using namespace std;

int cal(const vector<int>& numbers, const vector<char>& operators) {
    int sum = 0; bool minus = false;
    auto operator_it = operators.begin();

    for (const auto& num : numbers) {
        if (minus) sum -= num;
        else if (*operator_it == '-') {
            sum -= num;
            minus = true;
        }
        else {
            sum += num;
            ++operator_it;
        }
    }

    return sum;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    string str; cin >> str;

    vector<int> numbers;
    vector<char> operators;
    operators.emplace_back('+');

    int tmp = 0;
    for (const auto& ch : str) {
        if (ch >= 48 && ch <= 57) tmp = tmp * 10 + (ch - 48);
        else {
            numbers.emplace_back(tmp);
            tmp = 0;
            operators.emplace_back(ch);
        }
    }
    numbers.emplace_back(tmp);

    cout << cal(numbers, operators);
}