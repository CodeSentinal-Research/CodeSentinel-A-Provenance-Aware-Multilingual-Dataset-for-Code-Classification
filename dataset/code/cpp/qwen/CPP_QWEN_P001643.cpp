#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxWidth(TreeNode* root) {
    if (!root) return 0;
    queue<pair<TreeNode*, long long>> q;
    q.push({root, 0});
    int maxW = 0;
    
    while (!q.empty()) {
        int size = q.size();
        long long minIdx = q.front().second;
        long long first, last;
        for (int i = 0; i < size; ++i) {
            auto [node, idx] = q.front(); q.pop();
            idx -= minIdx;
            if (i == 0) first = idx;
            if (i == size - 1) last = idx;
            if (node->left) q.push({node->left, 2 * idx + 1});
            if (node->right) q.push({node->right, 2 * idx + 2});
        }
        maxW = max(maxW, (int)(last - first + 1));
    }
    return maxW;
}

int main() {
    int n;
    cin >> n;
    cout << "Requires specific tree building logic" << endl;
    return 0;
}
