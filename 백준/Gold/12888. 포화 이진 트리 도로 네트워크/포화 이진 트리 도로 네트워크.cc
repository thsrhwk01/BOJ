#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int main() {
    int n;
    cin >> n;

    vector<long long> vec(61);
    vec[0] = 1;

    for (int i = 1; i <= 60; i++) {
        vec[i] = vec[i - 1] * 2;

        if(i% 2) {
            vec[i]--;
        } else {
            vec[i]++;
        }
    }

    cout << vec[n];

    return 0;
}