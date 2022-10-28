#include <iostream>
#include <vector>

using namespace std;

class Person {
    int kg;
    int cm;
public:
    Person(int kg, int cm) : kg(kg), cm(cm) {}

    bool operator > (const Person &lhs) const {
        if (kg > lhs.kg && cm > lhs.cm) return true;
        else return false;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;

    vector<Person> vec;

    while (n--) {
        int kg, cm; cin >> kg >> cm;
        vec.emplace_back(kg, cm);
    }

    for (const auto& x : vec) {
        int rank = 1;
        for (const auto& y : vec) {
            if (y > x) ++rank;
        }

        cout << rank << '\n';
    }
}