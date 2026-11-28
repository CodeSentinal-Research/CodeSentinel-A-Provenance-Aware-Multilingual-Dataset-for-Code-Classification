#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

long long subtreeSum(TreeNode* root, long long totalSum, long long& maxProduct) {
    if (!root) return 0;
    long long sum = root->val + subtreeSum(root->left, totalSum, maxProduct) + subtreeSum(root->right, totalSum, maxProduct);
    long long otherPart = totalSum - sum;
    maxProduct = max(maxProduct, sum * otherPart);
    return sum;
}

int main() {
    int n;
    cin >> n;
    cout << "Requires specific tree building logic" << endl;
    return 0;
}
