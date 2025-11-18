#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isBSTUtil(TreeNode* root, int minVal, int maxVal) {
    if (!root) return true;
    if (root->val <= minVal || root->val >= maxVal) return false;
    return isBSTUtil(root->left, minVal, root->val) && isBSTUtil(root->right, root->val, maxVal);
}

bool isBST(TreeNode* root) {
    return isBSTUtil(root, -2147483648, 2147483647);
}

int main() {
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(10);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(15);

    cout << (isBST(root) ? "Tree is BST" : "Tree is not BST") << endl;
    return 0;
}
