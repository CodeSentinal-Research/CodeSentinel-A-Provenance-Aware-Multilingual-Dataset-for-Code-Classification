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

bool areCousins(TreeNode* root, int x, int y) {
    if (!root) return false;
    queue<pair<TreeNode*, TreeNode*>> q;
    q.push({root, NULL});
    
    while (!q.empty()) {
        int size = q.size();
        bool foundX = false, foundY = false;
        TreeNode* parentX = NULL, *parentY = NULL;
        
        for (int i = 0; i < size; ++i) {
            auto [node, parent] = q.front(); q.pop();
            if (node->val == x) { foundX = true; parentX = parent; }
            if (node->val == y) { foundY = true; parentY = parent; }
            if (node->left) q.push({node->left, node});
            if (node->right) q.push({node->right, node});
        }
        
        if (foundX && foundY) return parentX != parentY;
        if (foundX || foundY) return false;
    }
    return false;
}

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    cout << "Requires specific tree building logic" << endl;
    return 0;
}
