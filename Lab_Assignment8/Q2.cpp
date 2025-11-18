#include <iostream>
using namespace std;

struct BSTNode {
    int val;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int x) : val(x), left(NULL), right(NULL) {}
};

BSTNode* insert(BSTNode* root, int key) {
    if (!root) return new BSTNode(key);
    if (key < root->val) root->left = insert(root->left, key);
    else if (key > root->val) root->right = insert(root->right, key);
    return root;
}

BSTNode* search(BSTNode* root, int key) {
    if (!root || root->val == key) return root;
    return (key < root->val) ? search(root->left, key) : search(root->right, key);
}

BSTNode* findMin(BSTNode* root) {
    if (!root) return NULL;
    while (root->left) root = root->left;
    return root;
}

BSTNode* findMax(BSTNode* root) {
    if (!root) return NULL;
    while (root->right) root = root->right;
    return root;
}

// Successor
BSTNode* inorderSuccessor(BSTNode* root, BSTNode* node) {
    if (!node) return NULL;
    if (node->right) return findMin(node->right);
    BSTNode* succ = NULL;
    while (root) {
        if (node->val < root->val) { succ = root; root = root->left; }
        else if (node->val > root->val) root = root->right;
        else break;
    }
    return succ;
}

// Predecessor
BSTNode* inorderPredecessor(BSTNode* root, BSTNode* node) {
    if (!node) return NULL;
    if (node->left) return findMax(node->left);
    BSTNode* pred = NULL;
    while (root) {
        if (node->val > root->val) { pred = root; root = root->right; }
        else if (node->val < root->val) root = root->left;
        else break;
    }
    return pred;
}

int main() {
    BSTNode* root = NULL;
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 15);

    int key = 10;
    BSTNode* found = search(root, key);
    cout << "Search " << key << ": " << (found ? "Found" : "Not Found") << endl;
    cout << "Min: " << findMin(root)->val << endl;
    cout << "Max: " << findMax(root)->val << endl;
    cout << "Successor of " << key << ": " << (inorderSuccessor(root, found) ? inorderSuccessor(root, found)->val : -1) << endl;
    cout << "Predecessor of " << key << ": " << (inorderPredecessor(root, found) ? inorderPredecessor(root, found)->val : -1) << endl;

    return 0;
}
