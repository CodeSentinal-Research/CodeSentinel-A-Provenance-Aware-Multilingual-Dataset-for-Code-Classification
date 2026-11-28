#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return vector<TreeNode*>(1, nullptr);
        return generateTrees(1, n);
    }

private:
    vector<TreeNode*> generateTrees(int start, int end) {
        vector<TreeNode*> trees;
        if(start > end) {
            trees.push_back(nullptr);
            return trees;
        }

        for(int i = start; i <= end; i++) {
            for(auto &left : generateTrees(start, i-1)) {
                for(auto &right : generateTrees(i+1, end)) {
                    TreeNode *root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    trees.push_back(root);
                }
            }
        }
        return trees;
    }
};

int main() {
    int n;
    cin >> n;
    Solution solution;
    vector<TreeNode*> trees = solution.generateTrees(n);
    for(auto tree : trees) {
    }
    return 0;
}