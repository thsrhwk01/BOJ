//
// Created by woo-young Choi on 2022/08/14.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main () {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    double nums[3];
    while (true) {
        cin >> nums[0] >> nums[1] >> nums[2];
        if (nums[0] == 0 && nums[1] == 0 && nums[2] == 0) return 0;

        sort(begin(nums), end(nums));

        if ((nums[0] + nums[1] > nums[2]) && (nums[0] * nums[0] + nums[1] * nums[1] == nums[2] * nums[2])) cout << "right\n";
        else cout << "wrong\n";
    }
}