#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int getMaxDifference(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int maxDiff = 0;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node->left) {
            q.push(node->left);
        }
        if (node->right) {
            q.push(node->right);
        }

        if (maxDiff < node->val) {
            maxDiff = node->val;
        }
    }

    return maxDiff;
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
    }


    int maxDiff = getMaxDifference(root);
    cout << maxDiff << endl;

    return 0;
}