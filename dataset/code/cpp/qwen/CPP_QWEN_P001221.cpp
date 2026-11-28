#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode*> generateTrees(int start, int end) {
    vector<TreeNode*> trees;
    if (start > end) {
        trees.push_back(NULL);
        return trees;
    }
    
    for (int i = start; i <= end; ++i) {
        vector<TreeNode*> leftSubtrees = generateTrees(start, i - 1);
        vector<TreeNode*> rightSubtrees = generateTrees(i + 1, end);
        
        for (TreeNode* left : leftSubtrees) {
            for (TreeNode* right : rightSubtrees) {
                TreeNode* root = new TreeNode(i);
                root->left = left;
                root->right = right;
                trees.push_back(root);
            }
        }
    }
    return trees;
}

void printTree(TreeNode* root) {
    if (!root) {
        cout << "null ";
        return;
    }
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    int n;
    cin >> n;
    vector<TreeNode*> result = generateTrees(1, n);
    
    cout << result.size() << endl;
    for (TreeNode* tree : result) {
        printTree(tree);
        cout << endl;
    }
    
    return 0;
}
