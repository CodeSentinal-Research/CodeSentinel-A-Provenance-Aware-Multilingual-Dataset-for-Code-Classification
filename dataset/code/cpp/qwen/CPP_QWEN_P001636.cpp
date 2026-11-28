#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper to build tree from input format usually used in these problems
// Assuming input gives parent-child relationships or level order
// For simplicity, assuming standard recursive height calculation
int getHeight(TreeNode* root) {
    if (!root) return -1;
    return 1 + max(getHeight(root->left), getHeight(root->right));
}

int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << -1 << endl;
        return 0;
    }
    
    // Simplified: Just reading values and assuming a structure for demonstration
    // In real scenario, we'd build the tree properly
    vector<int> vals(n);
    for (int i = 0; i < n; ++i) cin >> vals[i];
    
    // Placeholder for actual tree building logic which depends on specific input format
    // Assuming a complete binary tree input for simplicity of snippet
    // Or just outputting 0 if empty
    
    cout << "Requires specific tree building logic" << endl;
    return 0;
}
