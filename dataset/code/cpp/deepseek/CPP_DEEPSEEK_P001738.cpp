#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Info {
    int size;
    int height;
    bool isComplete;
    Info(int s, int h, bool c) : size(s), height(h), isComplete(c) {}
};

Info* largestCompleteSubtree(TreeNode* root) {
    if (root == NULL) return new Info(0, 0, true);

    Info* leftInfo = largestCompleteSubtree(root->left);
    Info* rightInfo = largestCompleteSubtree(root->right);

    int size = leftInfo->size + rightInfo->size + 1;
    int height = max(leftInfo->height, rightInfo->height) + 1;
    bool isComplete = leftInfo->isComplete && rightInfo->isComplete && leftInfo->height == rightInfo->height;

    delete leftInfo;
    delete rightInfo;

    return new Info(size, height, isComplete);
}

int main() {

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
    }


    return 0;
}