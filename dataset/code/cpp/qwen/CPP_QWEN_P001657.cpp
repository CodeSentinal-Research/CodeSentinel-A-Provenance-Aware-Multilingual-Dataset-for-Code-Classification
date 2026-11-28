#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int minTimeToBurn(TreeNode* root, int target) {
    if (!root) return 0;
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
    
    unordered_set<TreeNode*> visited;
    queue<TreeNode*> burnQ;
    burnQ.push(targetNode);
    visited.insert(targetNode);
    int time = 0;
    
    while (!burnQ.empty()) {
        int size = burnQ.size();
        bool burned = false;
        for (int i = 0; i < size; ++i) {
            TreeNode* node = burnQ.front(); burnQ.pop();
            if (node->left && !visited.count(node->left)) {
                visited.insert(node->left);
                burnQ.push(node->left);
                burned = true;
            }
            if (node->right && !visited.count(node->right)) {
                visited.insert(node->right);
                burnQ.push(node->right);
                burned = true;
            }
            if (parentMap[node] && !visited.count(parentMap[node])) {
                visited.insert(parentMap[node]);
                burnQ.push(parentMap[node]);
                burned = true;
            }
        }
        if (burned) time++;
    }
    
    return time;
}

int main() {
    int n, target;
    cin >> n >> target;
    cout << "Requires specific tree building logic" << endl;
    return 0;
}
