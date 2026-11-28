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

bool isEvenOddTree(TreeNode* root) {
    if (!root) return true;
    queue<TreeNode*> q;
    q.push(root);
    bool evenLevel = true;
    
    while (!q.empty()) {
        int size = q.size();
        int prevVal = evenLevel ? 0 : 1000001;
        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front(); q.pop();
            if (evenLevel) {
                if (node->val % 2 == 0 || node->val <= prevVal) return false;
            } else {
                if (node->val % 2 != 0 || node->val >= prevVal) return false;
            }
            prevVal = node->val;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        evenLevel = !evenLevel;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    cout << "Requires specific tree building logic" << endl;
    return 0;
}
