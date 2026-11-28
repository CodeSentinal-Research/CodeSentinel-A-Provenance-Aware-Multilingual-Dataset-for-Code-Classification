#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->value = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

int insertNode(Node* root, int value) {
    if(root == nullptr) {
        root = createNode(value);
    } else {
        if(value < root->value) {
            root->left = insertNode(root->left, value);
        } else if(value > root->value) {
            root->right = insertNode(root->right, value);
        }
    }
    return root->value;
}

Node* createTree(int N, int arr[], int i) {
    Node* root = nullptr;
    for(int j=0; j<N; j++) {
        insertNode(root, arr[j]);
    }
    return root;
}

int height(Node* root) {
    if(root == nullptr) {
        return -1;
    } else {
        return max(height(root->left), height(root->right)) + 1;
    }
}

int findDeepest(Node* root, int h, int& maxHeight, int& minHeight) {
    if(root == nullptr) {
        return 0;
    } else if(h == maxHeight) {
        return root->value;
    } else if(h < maxHeight) {
        maxHeight = h;
        return -1;
    }
    int l = findDeepest(root->left, h+1, maxHeight, minHeight);
    int r = findDeepest(root->right, h+1, maxHeight, minHeight);
    if(l != -1) {
        return l;
    } else if(r != -1) {
        return r;
    }
    return -1;
}

Node* createSmallestSubtree(int N, int arr[]) {
    Node* root = createTree(N, arr, 0);
    int maxHeight = 0, minHeight = height(root);
    int result = findDeepest(root, 0, maxHeight, minHeight);
    return result == -1 ? nullptr : createNode(result);
}

int main() {
    int N;
    cin >> N;
    int arr[N];
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    Node* smallestSubtree = createSmallestSubtree(N, arr);
    cout << smallestSubtree->value;
    return 0;
}