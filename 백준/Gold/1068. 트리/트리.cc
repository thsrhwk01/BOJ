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

int nodeNumber, nodeDeleted, nodeRoot, ans;

vi childTmp[51];

struct node {
    int value;
    vector<node *> childList;

    node(int value) {
        this->value = value;

        for (auto &childNum : childTmp[value]) {
            if (childNum == nodeDeleted)
                continue;

            node *child = new node(childNum);
            childList.emb(child);
        }
    }

    ~node() {
        for (auto child : childList) {
            delete child;
        }
    }

    int count() {
        if (childList.empty()) return 1;

        int ret = 0;

        for (auto &child: childList) {
            ret += child->count();
        }

        return ret;
    }
};

void input() {
    cin >> nodeNumber;

    int parent;
    rep(i, 0, nodeNumber - 1) {
        cin >> parent;

        if (parent == -1)
            nodeRoot = i;
        else
            childTmp[parent].emb(i);
    }

    cin >> nodeDeleted;
}

void solve() {
    if (nodeRoot == nodeDeleted) return;

    auto *root = new node(nodeRoot);

    ans = root->count();
}

void output() { cout << ans; }

int main() {
    fastio;

    input();
    solve();
    output();
}