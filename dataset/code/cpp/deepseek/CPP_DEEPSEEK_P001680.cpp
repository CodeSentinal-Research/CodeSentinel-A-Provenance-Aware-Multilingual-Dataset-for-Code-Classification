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

vector<int> largestValues(TreeNode* root) {
    vector<int> res;
    if (root == NULL) {
        return res;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        int max_val = q.front()->val;

        for (int i = 0; i < size; i++) {
            if (q.front()->val > max_val) {
                max_val = q.front()->val;
            }

            if (q.front()->left != NULL) {
                q.push(q.front()->left);
            }

            if (q.front()->right != NULL) {
                q.push(q.front()->right);
            }

            q.pop();
        }

        res.push_back(max_val);
    }

    return res;
}

int main() {
    return 0;
}