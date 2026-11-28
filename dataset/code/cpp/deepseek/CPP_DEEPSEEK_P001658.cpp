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

TreeNode* createBinaryTree(vector<int>& descriptions) {
    if (descriptions.empty()) return nullptr;
    unordered_map<int, TreeNode*> nodeMap;
    TreeNode* root = new TreeNode(descriptions[0]);
    nodeMap[descriptions[0]] = root;
    queue<TreeNode*> nodes;
    nodes.push(root);
    for (size_t i = 1; i < descriptions.size(); i += 2) {
        int parent = descriptions[i - 1], child = descriptions[i];
        TreeNode* parentNode = nodeMap[parent];
        TreeNode* childNode = new TreeNode(child);
        nodes.push(childNode);
        if (parentNode->left) {
            parentNode->right = childNode;
        } else {
            parentNode->left = childNode;
        }
        nodeMap[child] = childNode;
    }
    return root;
}

vector<int> findNodes(TreeNode* root, int target, int k) {
    vector<int> res;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    unordered_map<TreeNode*, TreeNode*> parentMap;
    parentMap[root] = nullptr;
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        if (p.first->val == target && p.second == k) {
            res.push_back(p.first->val);
        }
        if (p.second < k && p.first->left) {
            parentMap[p.first->left] = p.first;
            q.push({p.first->left, p.second + 1});
        }
        if (p.second < k && p.first->right) {
            parentMap[p.first->right] = p.first;
            q.push({p.first->right, p.second + 1});
        }
    }
    return res;
}

int main() {
    int N;
    cin >> N;
    vector<int> descriptions(N * 2 - 1);
    for (int i = 0; i < N * 2 - 1; ++i) {
        cin >> descriptions[i];
    }
    int target, K;
    cin >> target >> K;
    TreeNode* root = createBinaryTree(descriptions);
    vector<int> res = findNodes(root, target, K);
    for (int v : res) {
        cout << v << " ";
    }
    return 0;
}