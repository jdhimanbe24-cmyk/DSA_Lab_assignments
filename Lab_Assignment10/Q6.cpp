// Check duplicates in a binary tree (using arrays)
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v){ val=v; left=right=NULL; }
};

bool checkDuplicates(TreeNode* root, int vals[], int &count) {
    if(root==NULL) return false;
    for(int i=0;i<count;i++)
        if(vals[i]==root->val) return true;
    vals[count++]=root->val;
    return checkDuplicates(root->left,vals,count) || checkDuplicates(root->right,vals,count);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(2); // duplicate

    int vals[100], count=0;
    if(checkDuplicates(root,vals,count))
        cout << "Duplicates Found" << endl;
    else
        cout << "No Duplicates" << endl;
    return 0;
}
