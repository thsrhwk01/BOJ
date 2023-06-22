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

int n;
bool ans;
char strs[10000][20];

struct Trie {
    Trie *nextTrie[10];
    bool finish = false, hasChild = false;

    ~Trie() { rep(i, 0, 9) delete (nextTrie[i]); }

    void insert(const char *key) {
        if (*key == '\0') {
            if (hasChild)
                ans = false;
            finish = true;
            return;
        }

        int curr = *key - '0';
        if (!nextTrie[curr]) {
            if (finish)
                ans = false;
            nextTrie[curr] = new Trie();
        }

        hasChild = true;
        nextTrie[curr]->insert(key + 1);
    }
};

void input() {
    cin >> n;

    rep(i, 0, n - 1) { cin >> strs[i]; }
}

void solve() {
    ans = true;

    Trie *root = new Trie();
    rep(i, 0, n - 1) {
        root->insert(strs[i]);
        
        if (!ans)
            break;
    }

    delete root;
}

void output() { cout << (ans ? "YES" : "NO") << endl; }

int main() {
    fastio;

    int t;
    cin >> t;

    while (t--) {
        input();
        solve();
        output();
    }
}