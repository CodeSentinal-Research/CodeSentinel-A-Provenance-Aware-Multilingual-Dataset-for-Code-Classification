#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node(int val) : val(val), left(NULL), right(NULL) {}
};

class Solution {
public:
    int longestZigZag(Node* root) {
        if (!root) return 0;
        int left = longestZigZag(root->left);
        int right = longestZigZag(root->right);
        int leftRight = dfs(root->left, root->right, 1);
        int rightLeft = dfs(root->right, root->left, 1);
        return max({left, right, leftRight, rightLeft}) + 1;
    }

private:
    int dfs(Node* a, Node* b, int zigzag) {
        if (!a && !b) return zigzag;
        if (!a || !b) return max(zigzag, (!a) + (!b));
        if (a->val == b->val) return dfs(a->left, b->right, zigzag + 1);
        return max(zigzag, max(dfs(a->left, b, zigzag + 1), dfs(a->right, b, zigzag + 1)));
    }
};

int main() {
}