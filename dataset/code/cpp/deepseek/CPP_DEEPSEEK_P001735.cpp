#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool checkSubTree(TreeNode* s, TreeNode* t) {
        if(s == nullptr && t != nullptr) return false;
        if(t == nullptr && s != nullptr) return true;
        if(s == nullptr && t == nullptr) return true;
        if(s->val != t->val) return false;
        return checkMirror(s->left, t->left) && checkMirror(s->right, t->right);
    }

    bool checkMirror(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q != nullptr) return false;
        if(q == nullptr && p != nullptr) return false;
        if(p == nullptr && q == nullptr) return true;
        if(p->val != q->val) return false;
        return checkMirror(p->left, q->right) && checkMirror(p->right, q->left);
    }
};

int main() {
    int N;
    cin >> N;
    vector<int> tree(N);
    for(int i = 0; i < N; i++) {
        cin >> tree[i];
    }
    TreeNode* root = new TreeNode(tree[0]);
    TreeNode* p = root;
    for(int i = 1; i < N; i++) {
        if(tree[i] == 1) {
            p->right = new TreeNode(tree[i+1]);
            i++;
        } else {
            p->left = new TreeNode(tree[i+1]);
            i++;
        }
        p = p->right;
    }
    Solution s;
    if(s.checkSubTree(root, root)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}