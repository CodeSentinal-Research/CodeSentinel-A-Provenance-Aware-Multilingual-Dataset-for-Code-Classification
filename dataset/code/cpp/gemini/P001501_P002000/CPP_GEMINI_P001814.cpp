#include <vector>
#include <climits>
#include <cmath>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    void inorder(TreeNode* node, std::vector<int>& arr) {
        if (!node) return;
        inorder(node->left, arr);
        arr.push_back(node->val);
        inorder(node->right, arr);
    }
public:
    std::vector<int> findClosestPair(TreeNode* root1, TreeNode* root2, int target) {
        std::vector<int> arr1, arr2;
        inorder(root1, arr1);
        inorder(root2, arr2);

        int i = 0, j = (int)arr2.size() - 1;
        long long bestDiff = LLONG_MAX;
        std::vector<int> res = {arr1[0], arr2.back()};

        while (i < (int)arr1.size() && j >= 0) {
            int curSum = arr1[i] + arr2[j];
            long long diff = std::abs((long long)curSum - target);
            if (diff < bestDiff) {
                bestDiff = diff;
                res = {arr1[i], arr2[j]};
            }
            if (curSum < target) i++;
            else j--;
        }
        return res;
    }
};