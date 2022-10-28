//
// Created by woo-young Choi on 2022/09/20.
//

#include <iostream>
#include <algorithm>

using namespace std;

int n;
int *postorder, *inorder_idx;

void input() {
    cin >> n;

    postorder = new int[n];
    inorder_idx = new int[n];

    int tmp;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        inorder_idx[tmp] = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> postorder[i];
    }
}

void dac(int istart, int iend, int pstart, int pend) {
    if (iend < istart || pend < pstart) return;
    cout << postorder[pend] << ' ';

    int idx = inorder_idx[postorder[pend]];

    dac(istart, idx - 1, pstart, pstart + (idx - istart) - 1);
    dac(idx + 1, iend, pstart + (idx - istart), pend - 1);
}

void solve() {
    dac(0, n-1, 0, n-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    solve();
}