#include <iostream>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* newTreeNode(int val) {
    TreeNode* node = new TreeNode(val);
    return node;
}

TreeNode* buildTree(int* inorder, int* postorder, int inStart, int inEnd, unordered_map<int, int>& idx) {
    if (inStart > inEnd) return NULL;
    int rootVal = postorder[*postIndex];
    TreeNode* node = newTreeNode(rootVal);
    if (inStart == inEnd) return node;
    int index = idx[rootVal];
    node->right = buildTree(inorder, postorder, index + 1, inEnd, idx);
    node->left = buildTree(inorder, postorder, inStart, index - 1, idx);
    return node;
}

bool isSubtree(TreeNode* s, TreeNode* t) {
    if (t == NULL) return true;
    if (s == NULL) return false;
    if (isSame(s, t)) return true;
    return isSubtree(s->left, t) || isSubtree(s->right, t);
}

bool isSame(TreeNode* p, TreeNode* q) {
    if (p == NULL && q == NULL) return true;
    if (p == NULL || q == NULL) return false;
    if (p->val != q->val) return false;
    return isSame(p->right, q->right) && isSame(p->left, q->left);
}

int main() {
    int N1, N2;
    cin >> N1;
    int inorder1[N1], postorder1[N1];
    unordered_map<int, int> idx1;
    for (int i = 0; i < N1; i++) {
        cin >> inorder1[i];
        idx1[inorder1[i]] = i;
    }
    cin >> N2;
    int inorder2[N2], postorder2[N2];
    unordered_map<int, int> idx2;
    for (int i = 0; i < N2; i++) {
        cin >> inorder2[i];
        idx2[inorder2[i]] = i;
    }
    TreeNode* s = buildTree(&inorder1[0], &postorder1[0], 0, N1 - 1, idx1);
    TreeNode* t = buildTree(&inorder2[0], &postorder2[0], 0, N2 - 1, idx2);
    cout << (isSubtree(s, t) ? "YES" : "NO");
    return 0;
}