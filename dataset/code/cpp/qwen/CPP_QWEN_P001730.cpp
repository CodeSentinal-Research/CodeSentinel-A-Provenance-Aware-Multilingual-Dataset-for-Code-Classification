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

void treeToDoublyList(TreeNode* root, TreeNode*& head, TreeNode*& tail) {
    if (!root) return;
    
    treeToDoublyList(root->left, head, tail);
    
    if (!head) {
        head = root;
        tail = root;
    } else {
        tail->right = root;
        root->left = tail;
        tail = root;
    }
    
    treeToDoublyList(root->right, head, tail);
}

void makeCircular(TreeNode* head, TreeNode*& tail) {
    if (!head) return;
    head->left = tail;
    tail->right = head;
}

void printCircularList(TreeNode* head) {
    if (!head) return;
    TreeNode* curr = head;
    do {
        cout << curr->val << " ";
        curr = curr->right;
    } while (curr != head);
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> vals(n);
    for (int i = 0; i < n; ++i) cin >> vals[i];
    
    TreeNode* root = buildTree(vals);
    TreeNode* head = NULL;
    TreeNode* tail = NULL;
    
    treeToDoublyList(root, head, tail);
    makeCircular(head, tail);
    
    printCircularList(head);
    
    return 0;
}
