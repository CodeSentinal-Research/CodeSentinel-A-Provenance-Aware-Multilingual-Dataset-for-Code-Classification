Here is the code snippet:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int longestUnivaluePath(Node* root) {
        if (root == nullptr) {
            return 0;
        }
        int maxPath = max(longestUnivaluePath(root->left), longestUnivaluePath(root->right));
        if (root->left != nullptr && root->left->val == root->val) {
            maxPath = max(maxPath, 1 + longestUnivaluePath(root->left->left) + longestUnivaluePath(root->left->right));
        }
        if (root->right != nullptr && root->right->val == root->val) {
            maxPath = max(maxPath, 1 + longestUnivaluePath(root->right->left) + longestUnivaluePath(root->right->right));
        }
        return maxPath;
    }
};

int main() {
    return 0;
}

This code first checks if the root node is null. If it is, it returns 0 as there is no path.
Then it calculates the maximum path from the left and right subtrees.
Then it checks if the left child node and the root node have the same value. If they do, it adds 1 to the current path and the paths from the left and right subtrees.
Finally, it returns the maximum of the paths found in the previous steps.