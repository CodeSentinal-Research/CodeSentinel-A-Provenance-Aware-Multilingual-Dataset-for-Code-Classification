#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int main() {
    int n; cin >> n;
    vector<int> vals(n);
    for (int i = 0; i < n; i++) cin >> vals[i];
    if (n == 0 || vals[0] == -1) {
        cout << "[]" << endl;
        return 0;
    }
    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(vals[0]);
    q.push(root);
    int idx = 1;
    vector<int> view;
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            TreeNode* node = q.front(); q.pop();
            if (i == sz - 1) view.push_back(node->val);
            if (idx < n && vals[idx] != -1) {
                node->left = new TreeNode(vals[idx]);
                q.push(node->left);
            }
            idx++;
            if (idx < n && vals[idx] != -1) {
                node->right = new TreeNode(vals[idx]);
                q.push(node->right);
            }
            idx++;
        }
    }
    for (int x : view) cout << x << " ";
    cout << endl;
    return 0;
}
