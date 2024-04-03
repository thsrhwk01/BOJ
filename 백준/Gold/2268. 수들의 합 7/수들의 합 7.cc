#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using tiii = tuple<int, int, int>;
using viii = vector<tiii>;

#define endl '\n'
#define em emplace
#define emb emplace_back
#define all(x) x.begin(), x.end()
#define rep(i, from, to) for (int i = from; i <= to; ++i)

class segmentTree {
   private:
    int size;
    std::vector<long long> tree;

    long long _init(const std::vector<long long> &vec, int start, int end,
                    int node) {
        if (start == end) {
            return tree[node] = vec[start];
        }

        int mid = (start + end) / 2;

        return tree[node] = _init(vec, start, mid, (node << 1)) +
                            _init(vec, mid + 1, end, (node << 1) + 1);
    }

    long long _sum(int start, int end, int left, int right, int node) {
        if (left > end or right < start) {
            return 0;
        }

        if (left <= start and right >= end) {
            return tree[node];
        }

        int mid = (start + end) / 2;

        return _sum(start, mid, left, right, (node << 1)) +
               _sum(mid + 1, end, left, right, (node << 1) + 1);
    }

    long long _modify(int start, int end, int left, int right, long long value,
                      int node) {
        if (left > end or right < start) {
            return tree[node];
        }

        if (start == end) {
            if (left <= start and right >= end) {
                return tree[node] = value;
            }

            return tree[node];
        }

        int mid = (start + end) / 2;

        return tree[node] =
                   _modify(start, mid, left, right, value, (node << 1)) +
                   _modify(mid + 1, end, left, right, value, (node << 1) + 1);
    }

   public:
    segmentTree(int size) {
        this->size = size;
        tree.resize(this->size * 4);
        std::fill(tree.begin(), tree.end(), 0);
    }

    segmentTree(const std::vector<long long> &vec) {
        this->size = vec.size();
        tree.resize(this->size * 4);
        std::fill(tree.begin(), tree.end(), 0);

        _init(vec, 0, size - 1, 1);
    }

    long long sum(int left, int right) {
        return _sum(0, size - 1, left, right, 1);
    }

    void modifyRange(int left, int right, long long value) {
        _modify(0, size - 1, left, right, value, 1);
    }

    void modifySingle(int idx, long long value) {
        _modify(0, size - 1, idx, idx, value, 1);
    }

    /*
    void print() {
        for (const auto &i : tree) {
            std::cout << i << ' ';
        }

        std::cout << std::endl;
    }
    */
};

int main() {
    iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    segmentTree *segTree = new segmentTree(n);

    while (m--) {
        int cmd;
        cin >> cmd;

        if (cmd == 0) {
            int left, right;
            cin >> left >> right;
            if (left > right) {
                swap(left, right);
            }

            cout << segTree->sum(left - 1, right - 1) << endl;
        } else {
            int idx, value;
            cin >> idx >> value;
            segTree->modifySingle(idx - 1, value);
        }
    }
    return 0;
}