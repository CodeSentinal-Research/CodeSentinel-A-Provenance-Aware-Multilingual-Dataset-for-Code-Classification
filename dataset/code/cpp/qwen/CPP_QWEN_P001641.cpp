#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSubtreeHelper(TreeNode* t1, TreeNode* t2) {
    if (!t2) return true;
    if (!t1) return false;
    if (t1->val != t2->val) return false;
    return isSubtreeHelper(t1->left, t2->left) && isSubtreeHelper(t1->right, t2->right);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (!subRoot) return true;
    if (!root) return false;
    if (isSubtreeHelper(root, subRoot)) return true;
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

int main() {
    int n1, n2;
    cin >> n1 >> n2;
    cout << "Requires specific tree building logic" << endl;
    return 0;
}
