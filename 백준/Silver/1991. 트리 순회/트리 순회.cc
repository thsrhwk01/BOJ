#include <iostream>

using namespace std;

//#define TEST1
//#define TEST2

#if defined(TEST1) || defined(TEST2)
#include <queue>
#include <cassert>
#include <fstream>
#include <chrono>

using namespace chrono;
#endif

struct node {
    node *left, *right;
    char key;

    node(char key) : key(key), left(nullptr), right(nullptr) {};

    node *search(char keyword) {
        if (this->key == keyword) return this;

        node *l = nullptr, *r = nullptr;
        if (left) l = left->search(keyword);
        if (right) r = right->search(keyword);

        if (!l && !r) return nullptr;
        else return l ? l : r;
    }

    void emplace(char left, char right) {
        if (left != '.') this->left = new node(left);
        if (right != '.') this->right = new node(right);
    }

    void preorder() {
        cout << this->key;
        if (left) left->preorder();
        if (right) right->preorder();
    }

    void inorder() {
        if (left) left->inorder();
        cout << this->key;
        if (right) right->inorder();
    }

    void postorder() {
        if (left) left->postorder();
        if (right) right->postorder();
        cout << this->key;
    }
};

node *root;

#if defined(TEST1) || defined(TEST2)
node *search(char key) {
    queue<node *> q;
    q.emplace(root);

    while (!q.empty()) {
        node *now = q.front();
        q.pop();

        if (now->key == key) return now;

        if (now->left) q.emplace(now->left);
        if (now->right) q.emplace(now->right);
    }
}
#endif

void input() {
#if defined(TEST1) || defined(TEST2)
    fstream f("1991.in");

    if (f.fail()) assert("Could not open file");

    int n;
    f >> n;

    root = new node('A');

    char where, a, b;
    for (int i = 0; i < n - 1; ++i) {
        f >> where >> a >> b;

#ifdef TEST1
        root->search(where)->emplace(a, b);
#else
        search(where)->emplace(a, b);
#endif
    }

#else
    int n;
    cin >> n;

    root = new node('A');

    char where, a, b;
    for (int i = 0; i < n - 1; ++i) {
        cin >> where >> a >> b;

        root->search(where)->emplace(a, b);
    }
#endif
}

void output() {
    root->preorder();
    cout << '\n';
    root->inorder();
    cout << '\n';
    root->postorder();
    cout << '\n';
}

int main() {
#if defined(TEST1) || defined(TEST2)
    auto start = system_clock::now();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    output();
#if defined(TEST1) || defined(TEST2)
    auto end = system_clock::now();
    nanoseconds time = end- start;
    cout << time.count();
#endif
}