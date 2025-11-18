#include <iostream>
using namespace std;

// -------------------- Part 1: Sum of Left Leaves --------------------
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int sumOfLeftLeaves(TreeNode* root) {
    if (!root) return 0;
    int sum = 0;
    if (root->left && !root->left->left && !root->left->right)
        sum += root->left->val;
    return sum + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}

// -------------------- Part 2: Count Unique BSTs --------------------
int countUniqueBST(int n) {
    if (n <= 1) return 1;
    int res = 0;
    for (int i = 1; i <= n; i++)
        res += countUniqueBST(i - 1) * countUniqueBST(n - i);
    return res;
}

// -------------------- Part 3: Maximum Depth --------------------
int maxDepth(TreeNode* root) {
    if (!root) return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return 1 + (l > r ? l : r);
}

// -------------------- Part 4: Right View --------------------
struct QueueNode {
    TreeNode* node;
    int level;
};

int rightView(TreeNode* root, int output[]) {
    if (!root) return 0;
    QueueNode queue[1000];
    int front = 0, rear = 0;
    int maxLevel = -1, count = 0;

    queue[rear++] = {root, 0};
    while (front < rear) {
        QueueNode qn = queue[front++];
        TreeNode* cur = qn.node;
        int level = qn.level;
        if (level > maxLevel) {
            output[count++] = cur->val;
            maxLevel = level;
        }
        if (cur->right) queue[rear++] = {cur->right, level + 1};
        if (cur->left) queue[rear++] = {cur->left, level + 1};
    }
    return count;
}

// -------------------- Part 5: Build Tree from Preorder + Inorder --------------------
TreeNode* buildFromPreIn(int pre[], int in[], int &idx, int l, int r) {
    if (l > r) return NULL;
    TreeNode* root = new TreeNode(pre[idx++]);
    int mid = l;
    while (mid <= r && in[mid] != root->val) mid++;
    root->left = buildFromPreIn(pre, in, idx, l, mid - 1);
    root->right = buildFromPreIn(pre, in, idx, mid + 1, r);
    return root;
}

// -------------------- Part 6: Build Tree from Inorder + Postorder --------------------
TreeNode* buildFromInPost(int in[], int post[], int &idx, int l, int r) {
    if (l > r) return NULL;
    TreeNode* root = new TreeNode(post[idx--]);
    int mid = l;
    while (mid <= r && in[mid] != root->val) mid++;
    root->right = buildFromInPost(in, post, idx, mid + 1, r);
    root->left = buildFromInPost(in, post, idx, l, mid - 1);
    return root;
}

// -------------------- Part 7: Merge Two BSTs into DLL --------------------
struct DLLNode {
    int val;
    DLLNode *prev, *next;
    DLLNode(int x) : val(x), prev(NULL), next(NULL) {}
};

void inorderToArray(TreeNode* root, int arr[], int &n) {
    if (!root) return;
    inorderToArray(root->left, arr, n);
    arr[n++] = root->val;
    inorderToArray(root->right, arr, n);
}

DLLNode* mergeBSTsToDLL(TreeNode* t1, TreeNode* t2) {
    int a[500], b[500], merged[1000];
    int n1 = 0, n2 = 0, n = 0;
    inorderToArray(t1, a, n1);
    inorderToArray(t2, b, n2);

    int i = 0, j = 0;
    while (i < n1 && j < n2)
        merged[n++] = (a[i] < b[j]) ? a[i++] : b[j++];
    while (i < n1) merged[n++] = a[i++];
    while (j < n2) merged[n++] = b[j++];

    DLLNode *head = NULL, *tail = NULL;
    for (int k = 0; k < n; k++) {
        DLLNode* node = new DLLNode(merged[k]);
        if (!head) head = tail = node;
        else { tail->next = node; node->prev = tail; tail = node; }
    }
    return head;
}

// -------------------- Helper Functions --------------------
TreeNode* buildTreeLevelOrder() {
    int n; cin >> n;
    if (n == 0) return NULL;
    TreeNode* nodes[1000];
    int val[1000];
    for (int i = 0; i < n; i++) { cin >> val[i]; nodes[i] = (val[i]==-1?NULL:new TreeNode(val[i])); }
    int j = 1;
    for (int i = 0; i < n && j < n; i++) {
        if (nodes[i]) {
            if (j < n) nodes[i]->left = nodes[j++];
            if (j < n) nodes[i]->right = nodes[j++];
        }
    }
    return nodes[0];
}

void printDLL(DLLNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " <-> ";
        head = head->next;
    }
    cout << endl;
}

void printArray(int arr[], int n) {
    for (int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
}

// -------------------- Main Menu --------------------
int main() {
    int choice;
    while (true) {
        cout << "\n---- Binary Tree & BST Menu ----\n";
        cout << "1. Sum of Left Leaves\n";
        cout << "2. Count Unique BSTs\n";
        cout << "3. Maximum Depth\n";
        cout << "4. Right View\n";
        cout << "5. Build Tree from Preorder + Inorder\n";
        cout << "6. Build Tree from Inorder + Postorder\n";
        cout << "7. Merge Two BSTs into DLL\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 0) break;

        switch (choice) {
            case 1: {
                cout << "Enter tree level-order (-1 for NULL, n nodes): ";
                TreeNode* root = buildTreeLevelOrder();
                cout << "Sum of Left Leaves: " << sumOfLeftLeaves(root) << endl;
                break;
            }
            case 2: {
                int n; cout << "Enter n: "; cin >> n;
                cout << "Number of Unique BSTs: " << countUniqueBST(n) << endl;
                break;
            }
            case 3: {
                cout << "Enter tree level-order (-1 for NULL, n nodes): ";
                TreeNode* root = buildTreeLevelOrder();
                cout << "Maximum Depth: " << maxDepth(root) << endl;
                break;
            }
            case 4: {
                cout << "Enter tree level-order (-1 for NULL, n nodes): ";
                TreeNode* root = buildTreeLevelOrder();
                int output[1000], sz = rightView(root, output);
                cout << "Right View: ";
                printArray(output, sz);
                break;
            }
            case 5: {
                int n; cout << "Number of nodes: "; cin >> n;
                int pre[100], in[100]; cout << "Enter preorder: "; for(int i=0;i<n;i++) cin>>pre[i];
                cout << "Enter inorder: "; for(int i=0;i<n;i++) cin>>in[i];
                int idx = 0; TreeNode* root = buildFromPreIn(pre, in, idx, 0, n-1);
                cout << "Tree built from Preorder + Inorder\n"; break;
            }
            case 6: {
                int n; cout << "Number of nodes: "; cin >> n;
                int in[100], post[100]; cout << "Enter inorder: "; for(int i=0;i<n;i++) cin>>in[i];
                cout << "Enter postorder: "; for(int i=0;i<n;i++) cin>>post[i];
                int idx = n-1; TreeNode* root = buildFromInPost(in, post, idx, 0, n-1);
                cout << "Tree built from Inorder + Postorder\n"; break;
            }
            case 7: {
                cout << "Enter BST1 in level order: ";
                TreeNode* t1 = buildTreeLevelOrder();
                cout << "Enter BST2 in level order: ";
                TreeNode* t2 = buildTreeLevelOrder();
                DLLNode* head = mergeBSTsToDLL(t1, t2);
                cout << "Merged DLL: "; printDLL(head); break;
            }
            default: cout << "Invalid choice.\n";
        }
    }
}
