struct ListNode {
    int val;
    ListNode *prev, *next;
    ListNode(int x) : val(x), prev(nullptr), next(nullptr) {}
};

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    ListNode* cur = nullptr;

    TreeNode* build(int count) {
        if (count <= 0) return nullptr;
        TreeNode* left = build(count / 2);
        TreeNode* root = new TreeNode(cur->val);
        cur = cur->next;
        root->left = left;
        root->right = build(count - count / 2 - 1);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int count = 0;
        ListNode* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        cur = head;
        return build(count);
    }
};