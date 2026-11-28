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
        cout << 0 << endl;
        return 0;
    }
    queue<pair<TreeNode*, long long>> q;
    TreeNode* root = new TreeNode(vals[0]);
    q.push({root, 0});
    int idx = 1;
    int maxWidth = 0;
    while (!q.empty()) {
        int sz = q.size();
        long long left = q.front().second, right = q.back().second;
        maxWidth = max(maxWidth, (int)(right - left + 1));
        for (int i = 0; i < sz; i++) {
            auto [node, pos] = q.front(); q.pop();
            if (idx < n && vals[idx] != -1) {
                node->left = new TreeNode(vals[idx]);
                q.push({node->left, 2 * pos + 1});
            }
            idx++;
            if (idx < n && vals[idx] != -1) {
                node->right = new TreeNode(vals[idx]);
                q.push({node->right, 2 * pos + 2});
            }
            idx++;
        }
    }
    cout << maxWidth << endl;
    return 0;
}
