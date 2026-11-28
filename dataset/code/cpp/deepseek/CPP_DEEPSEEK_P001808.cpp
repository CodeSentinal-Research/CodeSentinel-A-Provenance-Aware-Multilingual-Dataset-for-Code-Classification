#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* newNode(int val) {
    TreeNode* node = new TreeNode(val);
    return node;
}

TreeNode* sortedArrayToBST(vector<int> &nums, int start, int end) {
    if (start > end) {
        return NULL;
    }
    int mid = (start + end) / 2;
    TreeNode *root = newNode(nums[mid]);
    root->left = sortedArrayToBST(nums, start, mid - 1);
    root->right = sortedArrayToBST(nums, mid + 1, end);
    return root;
}

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2) {
        return NULL;
    }
    if (!t1) {
        return t2;
    }
    if (!t2) {
        return t1;
    }
    t1->val += t2->val;
    t1->left = mergeTrees(t1->left, t2->left);
    t1->right = mergeTrees(t1->right, t2->right);
    return t1;
}

int main() {
    int N1, N2;
    cin >> N1;
    vector<int> nums1(N1);
    for (int i = 0; i < N1; i++) {
        cin >> nums1[i];
    }
    cin >> N2;
    vector<int> nums2(N2);
    for (int i = 0; i < N2; i++) {
        cin >> nums2[i];
    }
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    TreeNode* t1 = sortedArrayToBST(nums1, 0, N1 - 1);
    TreeNode* t2 = sortedArrayToBST(nums2, 0, N2 - 1);
    TreeNode* merged = mergeTrees(t1, t2);
    return 0;
}