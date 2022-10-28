//
// Created by woo-young Choi on 2022/08/13.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void quick_sort(vector<int>&, int, int);

int main() {
    int n; cin >> n;
    vector<int> v(n);

    for_each(v.begin(), v.end(), [] (auto& x) {cin >> x;});

    quick_sort(v, 0, v.size() - 1);

    for (auto x : v) cout << x << '\n';
}

void quick_sort(vector<int>& v, int start, int end) {
    if (start >= end) return;
    int pivot = start;
    int left = start + 1, right = end;

    while (true) {
        while (left <= end && v[left] <= v[pivot]) ++left;
        while (right > start && v[right] >= v[pivot]) --right;

        if (right < left) { swap(v[pivot], v[right]); break; }
        else swap(v[left], v[right]);
    }

    quick_sort(v, start, right - 1);
    quick_sort(v, right + 1, end);
}
