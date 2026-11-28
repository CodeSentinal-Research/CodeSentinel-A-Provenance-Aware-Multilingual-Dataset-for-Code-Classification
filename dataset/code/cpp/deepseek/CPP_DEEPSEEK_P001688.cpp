Here is the C++ code:

#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int val) : val(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxProduct(Node* root) {
        long total = getTotal(root);
        long maxAns = 0;
        long cur = 0;
        getMax(root, total, maxAns, maxProduct);
        return maxAns;
    }

    long getTotal(Node* root) {
        if (root == nullptr) return 0;
        return root->val + getTotal(root->left) + getTotal(root->right);
    }

    void getMax(Node* root, long total, long& maxAns, long (&maxProduct)[2]) {
        if (root == nullptr) return;
        long cur = total - root->val;
        if (cur > maxProduct[0]) {
            maxProduct[0] = cur;
            maxProduct[1] = root->val;
            maxAns = max(maxAns, cur * root->val);
        }
        getMax(root->left, total, maxAns, maxProduct);
        getMax(root->right, total, maxAns, maxProduct);
    }
};

In this code, we first calculate the total sum of the tree, then find the maximum possible product. Note that the maximum product is calculated by subtracting the value of the node from the total sum and multiplying with the node's value. This is done to ensure that the maximum product is always the product of two largest numbers in the tree.