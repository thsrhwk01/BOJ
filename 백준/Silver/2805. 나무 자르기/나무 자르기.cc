#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

size_t bn(size_t size, const vector<unsigned int>& trees,
          size_t start, size_t end) {
    if (end - start == 1 || end - start == 0) {
        return start;
    } else {
        size_t cutting = (start + end) / 2;
        unsigned long long  total = 0;
        for (const auto& x : trees) {
            if (x > cutting) total += x - cutting;
        }

        if (total >= size) start = cutting;
        else end = cutting;

        return bn(size, trees, start, end);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    size_t n, size; cin >> n >> size;
    vector<unsigned int> trees(n);

    for (auto& x : trees) cin >> x;

    size_t res = bn(size, trees, 0, *max_element(trees.begin(), trees.end()));

    cout << res;
}