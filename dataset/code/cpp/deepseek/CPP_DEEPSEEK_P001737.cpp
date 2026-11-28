Sure, here is the complete C++ code for your problem:

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

int size[100000];
int height[100000];

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

Node* constructTreeUtil(int post[], int* postId, int start, int end) {
    if (start > end) {
        return NULL;
    }
    Node* node = newNode(post[*postId]);
    (*postId)--;
    if (start == end) {
        return node;
    }
    int i = find(post, post + end + 1, *node->data) - post;
    node->right = constructTreeUtil(post, postId, i, end);
    node->left = constructTreeUtil(post, postId, start, i - 1);
    return node;
}

Node* constructTree(int post[], int postSize) {
    int postId = postSize - 1;
    return constructTreeUtil(post, &postId, 0, postSize - 1);
}

int heightUtil(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return max(heightUtil(node->left), heightUtil(node->right)) + 1;
}

int largestPerfectTree(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int h = heightUtil(root);
    int h2 = heightUtil(root->right);
    int h3 = heightUtil(root->left);
    if (h == h2 && h2 == h3 && h == h3) {
        return h;
    }
    else if (h2 > h && h2 > h3) {
        return h2;
    }
    else if (h3 > h && h3 > h2) {
        return h3;
    }
    else {
        return h;
    }
}

int main() {
    int post[] = {1, 2, 3, 4, 5, 6, 7};
    int postSize = sizeof(post) / sizeof(post[0]);
    Node* root = constructTree(post, postSize);
    cout << "Size of largest perfect subtree is " << largestPerfectTree(root);
    return 0;
}

Please note that you need to provide the postorder traversal of the binary tree to construct the tree. The `constructTree` function creates a binary tree from a postorder traversal. The `largestPerfectTree` function finds the size of the largest perfect subtree in the binary tree.