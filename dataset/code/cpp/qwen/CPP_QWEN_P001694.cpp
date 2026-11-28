#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int closestLeaf(TreeNode* root, int target) {
    if (!root) return -1;
    unordered_map<TreeNode*, TreeNode*> parentMap;
    TreeNode* targetNode = NULL;
    queue<TreeNode*> q;
    q.push(root);
    parentMap[root] = NULL;
    
    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        if (node->val == target) targetNode = node;
        if (node->left) {
            parentMap[node->left] = node;
            q.push(node->left);
        }
        if (node->right) {
            parentMap[node->right] = node;
            q.push(node->right);
        }
    }
    
    queue<TreeNode*> bfsQ;
    unordered_set<TreeNode*> visited;
    bfsQ.push(targetNode);
    visited.insert(targetNode);
    
    while (!bfsQ.empty()) {
        TreeNode* node = bfsQ.front(); bfsQ.pop();
        if (!node->left && !node->right) return node->val;
        
        if (node->left && !visited.count(node->left)) {
            visited.insert(node->left);
            bfsQ.push(node->left);
        }
        if (node->right && !visited.count(node->right)) {
            visited.insert(node->right);
            bfsQ.push(node->right);
        }
        if (parentMap[node] && !visited.count(parentMap[node])) {
            visited.insert(parentMap[node]);
            bfsQ.push(parentMap[node]);
        }
    }
    return -1;
}

int main() {
    int n, target;
    cin >> n >> target;
    cout << "Requires specific tree building logic" << endl;
    return 0;
}
