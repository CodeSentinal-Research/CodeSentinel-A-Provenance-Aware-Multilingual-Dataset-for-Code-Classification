#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

Node* buildTree(vector<int>& preorder, vector<int>& postorder) {
    if (preorder.empty())
        return nullptr;

    int rootVal = preorder[0];
    preorder.erase(preorder.begin());

    Node* root = new Node(rootVal);

    if (preorder.empty())
        return root;

    int leftRootVal = preorder[0];
    preorder.erase(preorder.begin());

    Node* left = new Node(leftRootVal);
    root->left = left;

    if (preorder.empty())
        return root;

    int rightRootVal = postorder.back();
    postorder.pop_back();

    Node* right = new Node(rightRootVal);
    root->right = right;

    vector<int> leftPreorder, rightPreorder, leftPostorder, rightPostorder;
    leftPreorder.assign(preorder.begin(), preorder.begin() + leftRootVal);
    rightPreorder.assign(preorder.begin() + leftRootVal, preorder.end());
    leftPostorder.assign(postorder.begin(), postorder.begin() + leftRootVal);
    rightPostorder.assign(postorder.begin() + leftRootVal, postorder.end());

    left->left = buildTree(leftPreorder, leftPostorder);
    left->right = buildTree(rightPreorder, rightPostorder);
    right->left = buildTree(leftPreorder, leftPostorder);
    right->right = buildTree(rightPreorder, rightPostorder);

    return root;
}

int main() {
    int n;
    cin >> n;
    vector<int> preorder(n), postorder(n);
    for (int i = 0; i < n; i++) {
        cin >> preorder[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> postorder[i];
    }

    Node* root = buildTree(preorder, postorder);

    return 0;
}