#include <iostream>
#include <vector>
#include <queue>
#include <map>
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
    queue<pair<TreeNode*, int>> q;
    TreeNode* root = new TreeNode(vals[0]);
    q.push({root, 0});
    int idx = 1;
    map<int, int> bottom;
    while (!q.empty()) {
        auto [node, col] = q.front(); q.pop();
        bottom[col] = node->val;
        if (idx < n && vals[idx] != -1) {
            node->left = new TreeNode(vals[idx]);
            q.push({node->left, col - 1});
        }
        idx++;
        if (idx < n && vals[idx] != -1) {
            node->right = new TreeNode(vals[idx]);
            q.push({node->right, col + 1});
        }
        idx++;
    }
    for (auto& p : bottom) {
        cout << p.second << " ";
    }
    cout << endl;
    return 0;
}
