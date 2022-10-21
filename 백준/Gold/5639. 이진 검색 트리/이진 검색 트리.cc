//
// Created by 99woo on 2022-10-19.
//

#include <bits/stdc++.h>

using namespace std;

struct node {
    node *left, *right;
    int key;

    node(int key) : key(key), left(nullptr), right(nullptr) {};

    node *search(int keyword) {
        if (this->key == keyword) return this;

        if (keyword > this->key) return right ? right->search(keyword) : right;
        else return left ? left->search(keyword) : left;
    }

    void emplace(int i) {
        if (key < i) {
            if (right != nullptr) right->emplace(i);
            else right = new node(i);
        }
        else {
            if (left != nullptr) left->emplace(i);
            else left = new node(i);
        }
    }

    void preorder() {
        cout << this->key << '\n';
        if (left) left->preorder();
        if (right) right->preorder();
    }

    void inorder() {
        if (left) left->inorder();
        cout << this->key << '\n';
        if (right) right->inorder();
    }

    void postorder() {
        if (left) left->postorder();
        if (right) right->postorder();
        cout << this->key << '\n';
    }
};

node *root;

void solve() {
    int i;
    cin >> i;

    root = new node(i);

    while (cin >> i) {
        root->emplace(i);
    }
}

void output() {
    root->postorder();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    output();
}