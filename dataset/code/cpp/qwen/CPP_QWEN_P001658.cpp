#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*, TreeNode*> parentMap;
    queue<TreeNode*> q;
    q.push(root);
    parentMap[root] = NULL;
    
    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
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
    queue<TreeNode*> bfsQ;
    bfsQ.push(target);
    visited.insert(target);
    int currDist = 0;
    
    while (!bfsQ.empty() && currDist < k) {
        int size = bfsQ.size();
        for (int i = 0; i < size; ++i) {
            TreeNode* node = bfsQ.front(); bfsQ.pop();
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
        currDist++;
    }
    
    vector<int> result;
    while (!bfsQ.empty()) {
        result.push_back(bfsQ.front()->val);
        bfsQ.pop();
    }
    return result;
}

int main() {
    int n, target, k;
    cin >> n >> target >> k;
    cout << "Requires specific tree building logic" << endl;
    return 0;
}
