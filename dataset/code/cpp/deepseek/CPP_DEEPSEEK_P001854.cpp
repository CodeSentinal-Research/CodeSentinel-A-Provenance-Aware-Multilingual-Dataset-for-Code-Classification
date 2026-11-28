#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int priority;
    int inorderIndex;
    int leftChildIndex;
    int rightChildIndex;
};

void storeInorder(int inorderIndex, int priority, vector<int> &inorder, vector<Node> &tree) {
    Node node;
    node.priority = priority;
    node.inorderIndex = inorderIndex;
    node.leftChildIndex = -1;
    node.rightChildIndex = -1;
    tree.push_back(node);
}

int findUncle(int index, vector<Node> &tree) {
    if (index == 0) return -1;
    int parentIndex = tree[index].inorderIndex;
    for (int i = 0; i < parentIndex; i++) {
        if (tree[i].rightChildIndex == index) {
            return tree[i].inorderIndex;
        }
    }
    return -1;
}

void buildTree(int &index, vector<Node> &tree, vector<int> &inorder) {
    if (index == -1) return;
    int leftIndex = tree[index].leftChildIndex;
    int rightIndex = tree[index].rightChildIndex;
    buildTree(leftIndex, tree, inorder);
    buildTree(rightIndex, tree, inorder);
}

int main() {
    int N;
    cin >> N;
    vector<int> inorder(N);
    for (int i = 0; i < N; i++) {
        cin >> inorder[i];
    }
    vector<int> priority(N);
    for (int i = 0; i < N; i++) {
        cin >> priority[i];
    }
    vector<Node> tree;
    for (int i = 0; i < N; i++) {
        storeInorder(i, priority[i], inorder, tree);
    }
    for (int i = 0; i < N; i++) {
        if (tree[i].leftChildIndex == -1) {
            tree[i].leftChildIndex = findUncle(i, tree);
        } else if (tree[i].rightChildIndex == -1) {
            tree[i].rightChildIndex = findUncle(i, tree);
        }
    }
    int rootIndex = 0;
    while (tree[rootIndex].leftChildIndex != -1) {
        rootIndex = tree[rootIndex].leftChildIndex;
    }
    buildTree(rootIndex, tree, inorder);
    return 0;
}