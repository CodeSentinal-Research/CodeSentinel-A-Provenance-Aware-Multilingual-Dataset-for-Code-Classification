Here's a simple C++ solution to check whether two trees are isomorphic. This solution uses a depth-first search (DFS) approach to traverse both trees. For each node in the first tree, we check if it can be reached in the second tree by swapping its children.

#include <iostream>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isIsomorphic(TreeNode* t1, TreeNode* t2) {
    if (t1 == nullptr && t2 == nullptr) return true;
    if (t1 == nullptr || t2 == nullptr) return false;
    if (t1->val != t2->val) return false;

    return (isIsomorphic(t1->left, t2->left) && isIsomorphic(t1->right, t2->right))
        || (isIsomorphic(t1->left, t2->right) && isIsomorphic(t1->right, t2->left));
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
    }

    bool isomorphic = isIsomorphic(t1, t2);
    cout << (isomorphic ? "YES" : "NO") << endl;

    return 0;
}
Please note that this code assumes that the trees are constructed from a root node. The tree nodes are represented as a structure with a value and two pointers to the left and right children.