#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(vector<int>& vals) {
    if (vals.empty() || vals[0] == -1) return NULL;
    TreeNode* root = new TreeNode(vals[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < vals.size()) {
        TreeNode* node = q.front(); q.pop();
        if (i < vals.size() && vals[i] != -1) {
            node->left = new TreeNode(vals[i]);
            q.push(node->left);
        }
        i++;
        if (i < vals.size() && vals[i] != -1) {
            node->right = new TreeNode(vals[i]);
            q.push(node->right);
        }
        i++;
    }
    return root;
}

void insertLevel(TreeNode*& root, int val, int depth) {
    if (!root) {
        root = new TreeNode(val);
        return;
    }
    if (depth == 1) {
        TreeNode* newNode = new TreeNode(val);
        newNode->left = root->left;
        newNode->right = root->right;
        root->left = newNode;
        root->right = newNode; // This logic is flawed for general case, assuming specific problem constraints or simplified structure
        // Correct logic: Insert a row of nodes with value val at depth d.
        // If d==1, create new root.
        // Else, at depth d-1, insert new nodes as children.
    }
}

// Simplified implementation for standard "Add One Row" problem
TreeNode* addOneRow(TreeNode* root, int val, int depth) {
    if (depth == 1) {
        TreeNode* newNode = new TreeNode(val);
        newNode->left = root;
        return newNode;
    }
    
    queue<TreeNode*> q;
    q.push(root);
    int currDepth = 1;
    
    while (!q.empty()) {
        int size = q.size();
        if (currDepth == depth - 1) {
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front(); q.pop();
                TreeNode* leftChild = node->left;
                TreeNode* rightChild = node->right;
                
                node->left = new TreeNode(val);
                node->left->left = leftChild;
                
                node->right = new TreeNode(val);
                node->right->right = rightChild;
            }
            break;
        }
        
        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front(); q.pop();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        currDepth++;
    }
    return root;
}

void printLevelOrder(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        cout << node->val << " ";
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> vals(n);
    for (int i = 0; i < n; ++i) cin >> vals[i];
    
    int val, d;
    cin >> val >> d;
    
    TreeNode* root = buildTree(vals);
    root = addOneRow(root, val, d);
    printLevelOrder(root);
    
    return 0;
}
