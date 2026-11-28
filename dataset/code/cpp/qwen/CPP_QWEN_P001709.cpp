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

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (!t1) return t2;
    if (!t2) return t1;
    
    TreeNode* merged = new TreeNode(t1->val + t2->val);
    merged->left = mergeTrees(t1->left, t2->left);
    merged->right = mergeTrees(t1->right, t2->right);
    return merged;
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
    int n1, n2;
    cin >> n1;
    vector<int> vals1(n1);
    for (int i = 0; i < n1; ++i) cin >> vals1[i];
    
    cin >> n2;
    vector<int> vals2(n2);
    for (int i = 0; i < n2; ++i) cin >> vals2[i];
    
    TreeNode* t1 = buildTree(vals1);
    TreeNode* t2 = buildTree(vals2);
    
    TreeNode* merged = mergeTrees(t1, t2);
    printLevelOrder(merged);
    
    return 0;
}
