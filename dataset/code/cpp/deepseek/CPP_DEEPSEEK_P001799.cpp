#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthLargestElement(TreeNode* root, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        inorder(root, k, pq);
        while(--k) {
            pq.pop();
        }
        return pq.top();
    }

private:
    void inorder(TreeNode* node, int& k, priority_queue<int, vector<int>, greater<int>>& pq) {
        if (!node) {
            return;
        }
        inorder(node->right, k, pq);
        if (pq.size() == k) {
            pq.pop();
        }
        pq.push(node->val);
        inorder(node->left, k, pq);
    }
};

This code firstly defines the TreeNode structure and the solution class. In the solution class, the `kthLargestElement` function is defined, which uses a priority queue to keep track of the K largest elements in the Binary Search Tree (BST). The `inorder` function is a helper function that visits the BST in inorder (left-right-root) order, and pushes the largest k elements into the priority queue. The main function takes the root of the BST and K as input, and prints the Kth largest element.