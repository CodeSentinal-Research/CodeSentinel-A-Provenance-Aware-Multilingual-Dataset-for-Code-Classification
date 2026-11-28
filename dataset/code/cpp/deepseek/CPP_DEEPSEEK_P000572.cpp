#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (root == NULL) return res;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int levelNum = q.size();
        vector<int> currentLevel;
        
        for (int i = 0; i < levelNum; i++) {
            TreeNode* node = q.front();
            q.pop();
            
            currentLevel.push_back(node->val);
            
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        
        res.push_back(currentLevel);
    }
    
    return res;
}

int main() {
    return 0;
}