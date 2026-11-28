#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(vector<int>& vals) {
    if (vals.empty() || vals[0] == -1) return NULL;
    TreeNode* root = new TreeNode(vals[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < vals.size()) {
        TreeNode* node = q.front(); q.pop();
        if (i < vals.size() && vals[i] != -1) {
            node->left = new TreeNode(vals[i]);
            q.push(node->left);
        }
        i++;
        if (i < vals.size() && vals[i] != -1) {
            node->right = new TreeNode(vals[i]);
            q.push(node->right);
        }
        i++;
    }
    return root;
}

void findAntiDiagonalSums(TreeNode* root, map<int, long long>& antiDiagonalSums, int d) {
    if (!root) return;
    antiDiagonalSums[d] += root->val;
    findAntiDiagonalSums(root->left, antiDiagonalSums, d);
    findAntiDiagonalSums(root->right, antiDiagonalSums, d + 1);
}

int main() {
    int n;
    cin >> n;
    vector<int> vals(n);
    for (int i = 0; i < n; ++i) cin >> vals[i];
    
    TreeNode* root = buildTree(vals);
    map<int, long long> antiDiagonalSums;
    findAntiDiagonalSums(root, antiDiagonalSums, 0);
    
    for (auto& p : antiDiagonalSums) {
        cout << p.second << " ";
    }
    cout << endl;
    
    return 0;
}
