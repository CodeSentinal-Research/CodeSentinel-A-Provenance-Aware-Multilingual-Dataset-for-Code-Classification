#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> largestValues(TreeNode* root) {
    vector<int> result;
    if (!root) return result;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        int maxVal = INT_MIN;
        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front(); q.pop();
            maxVal = max(maxVal, node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        result.push_back(maxVal);
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    cout << "Requires specific tree building logic" << endl;
    return 0;
}
