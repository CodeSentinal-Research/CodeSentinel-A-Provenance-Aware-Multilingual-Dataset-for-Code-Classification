#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (root == NULL) return result;
        
        queue<pair<TreeNode*, int>> myQueue;
        myQueue.push({root, 0});
        
        while(!myQueue.empty()) {
            int size = myQueue.size();
            for(int i = 0; i < size; i++) {
                TreeNode* node = myQueue.front().first;
                int level = myQueue.front().second;
                myQueue.pop();
                
                if(i == size - 1) {
                    result.push_back(node->val);
                }
                
                if(node->right) {
                    myQueue.push({node->right, level + 1});
                }
                if(node->left) {
                    myQueue.push({node->left, level + 1});
                }
            }
        }
        
        return result;
    }
};

int main() {
    return 0;
}