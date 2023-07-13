#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

#define endl '\n'
#define em emplace
#define emb emplace_back
#define all(x) x.begin(), x.end()
#define rep(i, from, to) for (int i = from; i <= to; ++i)
#define fastio                                                                 \
    iostream::sync_with_stdio(false);                                          \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);

int n, resIdx;

array<int, 10'001> arrOriginal;

vii results, resultsTmp;

void forwardFlip(array<int, 10'001> arr, int cnt);
void backwardFlip(array<int, 10'001> arr, int cnt);

void input() {
    cin >> n;

    rep(i, 1, n) { cin >> arrOriginal[i]; }
}

void forwardFlip(array<int, 10'001> arr, int cnt) {
    if (!results.empty())
        return;

    if (cnt == 2) {
        if (is_sorted(arr.begin(), arr.begin() + n + 1))
            results = resultsTmp;

        return;
    }

    pii tmp = {1, 1};
    rep(i, 1, n) {
        if (arr[i] != i) {
            int j = i;

            while (j <= n && arr[j] != i)
                ++j;

            reverse(arr.begin() + i, arr.begin() + j + 1);

            tmp = {i, j};
            break;
        }
    }

    resultsTmp.emb(tmp);

    forwardFlip(arr, cnt + 1);
    backwardFlip(arr, cnt + 1);

    resultsTmp.pop_back();
}

void backwardFlip(array<int, 10'001> arr, int cnt) {
    if (!results.empty())
        return;

    if (cnt == 2) {
        if (is_sorted(arr.begin(), arr.begin() + n + 2))
            results = resultsTmp;

        return;
    }

    pii tmp = {1, 1};
    for (int i = n; i > 0; --i) {
        if (arr[i] != i) {
            int j = i;

            while (j > 0 && arr[j] != i)
                --j;

            reverse(arr.begin() + j, arr.begin() + i + 1);

            tmp = {j, i};
            break;
        }
    }

    resultsTmp.emb(tmp);

    forwardFlip(arr, cnt + 1);
    backwardFlip(arr, cnt + 1);

    resultsTmp.pop_back();
}

void solve() {
    arrOriginal[n + 1] = n + 1;

    forwardFlip(arrOriginal, 0);
    backwardFlip(arrOriginal, 0);
}

void output() {
    for (auto result : results)
        cout << result.first << ' ' << result.second << endl;
}

int main() {
    fastio;

    input();
    solve();
    output();
}