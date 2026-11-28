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
    vector<vector<int>> levels;
    bool leftToRight = true;
    while (!q.empty()) {
        int sz = q.size();
        vector<int> level(sz);
        for (int i = 0; i < sz; i++) {
            TreeNode* node = q.front(); q.pop();
            int index = leftToRight ? i : sz - 1 - i;
            level[index] = node->val;
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
        levels.push_back(level);
        leftToRight = !leftToRight;
    }
    for (auto& level : levels) {
        cout << "[";
        for (int i = 0; i < level.size(); i++) {
            if (i > 0) cout << ",";
            cout << level[i];
        }
        cout << "] ";
    }
    cout << endl;
    return 0;
}
