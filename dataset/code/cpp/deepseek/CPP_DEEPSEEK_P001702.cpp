#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int countGoodNodes(TreeNode* root) {
    return countGoodNodesUtil(root, INT_MIN);
}

int countGoodNodesUtil(TreeNode* node, int maxVal) {
    if (!node) return 0;

    int goodNodes = 0;
    if (node->val >= maxVal) goodNodes = 1;

    return goodNodes + countGoodNodesUtil(node->left, max(maxVal, node->val))
           + countGoodNodesUtil(node->right, max(maxVal, node->val));
}

int main() {
    int N;
    cin >> N;

    vector<int> nodes;
    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        nodes.push_back(val);
    }

    vector<TreeNode*> tree(N);
    for (int i = 0; i < N; i++) {
        if (2*i+1 < N) {
            tree[i]->left = tree[2*i+1];
        }
        if (2*i+2 < N) {
            tree[i]->right = tree[2*i+2];
        }
    }

    cout << countGoodNodes(tree[0]);

    return 0;
}