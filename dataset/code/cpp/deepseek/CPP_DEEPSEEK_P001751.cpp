#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = node->right = nullptr;
    return node;
}

Node* buildTree(vector<int>& inorder, vector<int>& postorder, int startInorder, int endInorder, int startPostorder, int endPostorder) {
    if (startPostorder > endPostorder) {
        return nullptr;
    }

    Node* node = newNode(postorder[endPostorder]);

    int rootIndex = find(inorder.begin() + startInorder, inorder.begin() + endInorder, node->data) - inorder.begin();

    node->left = buildTree(inorder, postorder, startInorder, rootIndex - 1, startPostorder, startPostorder + rootIndex - endInorder - 1);
    node->right = buildTree(inorder, postorder, rootIndex + 1, endInorder, endPostorder - endInorder + rootIndex, endPostorder);

    return node;
}

int countDescendants(Node* root, int k) {
    if (root == nullptr) {
        return 0;
    }

    if (root->left == nullptr && root->right == nullptr) {
        return k == 0;
    }

    int count = 0;
    if (root->left != nullptr) {
        count += countDescendants(root->left, k - 1);
    }
    if (root->right != nullptr) {
        count += countDescendants(root->right, k);
    }

    return count;
}

int main() {
    int N;
    cin >> N;

    vector<int> inorder(N), postorder(N);
    for (int i = 0; i < N; i++) {
        cin >> inorder[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> postorder[i];
    }

    int K;
    cin >> K;

    Node* root = buildTree(inorder, postorder, 0, N - 1, 0, N - 1);
    cout << countDescendants(root, K);

    return 0;
}