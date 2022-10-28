#include <iostream>
#include <algorithm>

using namespace std;

int now_max[3] = {0, 0, 0};
int now_min[3] = {0, 0, 0};
int before_max[3] = {0, 0, 0};
int before_min[3] = {0, 0, 0};

void input() {
    int n, s1, s2, s3;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        swap(now_max, before_max);
        swap(now_min, before_min);

        cin >> s1 >> s2 >> s3;
        now_max[0] = max(before_max[0], before_max[1]) + s1;
        now_max[1] = *max_element(before_max, before_max + 3) + s2;
        now_max[2] = max(before_max[1], before_max[2]) + s3;

        now_min[0] = min(before_min[0], before_min[1]) + s1;
        now_min[1] = *min_element(before_min, before_min + 3) + s2;
        now_min[2] = min(before_min[1], before_min[2]) + s3;
    }
}

void output() {
    cout << *max_element(now_max, now_max + 3)
         << '\n' << *min_element(now_min, now_min + 3);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    output();
}
