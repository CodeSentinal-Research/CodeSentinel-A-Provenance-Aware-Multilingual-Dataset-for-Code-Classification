Here is the C++ code to solve the problem:

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int inIndex = 0;

TreeNode* buildTree(vector<int>& inorder, vector<int>& levelorder, int start, int end) {
    if (start > end) {
        return NULL;
    }

    int iIndex = inIndex++;
    if (inorder[iIndex] != levelorder[start]) {
        return NULL;
    }

    TreeNode* root = new TreeNode(levelorder[start]);

    root->left = buildTree(inorder, levelorder, start, iIndex - 1);
    root->right = buildTree(inorder, levelorder, iIndex + 1, end);

    return root;
}

TreeNode* reconstruct(vector<int>& levelorder, vector<int>& inorder) {
    int n = levelorder.size();
    return buildTree(inorder, levelorder, 0, n - 1);
}

int main() {
    int n;
    cin >> n;

    vector<int> levelorder(n);
    for (int i = 0; i < n; i++) {
        cin >> levelorder[i];
    }

    vector<int> inorder(n);
    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
    }

    TreeNode* root = reconstruct(levelorder, inorder);

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        cout << node->val << " ";

        if (node->left) {
            q.push(node->left);
        }
        if (node->right) {
            q.push(node->right);
        }
    }

    return 0;
}

This code constructs a binary tree from the given level and inorder traversal and then prints the tree in level order traversal. The level order traversal is done using a queue and the queue is populated with the root of the tree. The while loop in the main function continues until the queue is empty. In each iteration, the front of the queue is popped and its value is printed. If the node has a left or right child, these are pushed into the queue.