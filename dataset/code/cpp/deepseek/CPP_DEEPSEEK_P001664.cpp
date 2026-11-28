Here is the C++ code for your problem:

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory error\n";
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* buildTree(vector<int>& preOrder, vector<int>& inOrder, int startIn, int endIn, int startPre, int endPre) {
    if (startIn > endIn) {
        return NULL;
    }

    Node* root = createNode(preOrder[startPre]);

    int rootIndex = -1;
    for (int i = startIn; i <= endIn; i++) {
        if (inOrder[i] == preOrder[startPre]) {
            rootIndex = i;
            break;
        }
    }

    int leftLength = rootIndex - startIn;
    int rightLength = endIn - rootIndex;

    startPre++;

    root->left = buildTree(preOrder, inOrder, startIn, rootIndex - 1, startPre, startPre + leftLength - 1);
    root->right = buildTree(preOrder, inOrder, rootIndex + 1, endIn, startPre + leftLength, endPre);

    return root;
}

bool isPerfect(Node* root) {
    if (!root) {
        return true;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* node = q.front();
        q.pop();

        if (!node->left && !node->right) {
            if (q.front() != node) {
                return false;
            }
        } else if (node->left && node->right) {
            if (!q.front() || q.front() != node) {
                return false;
            }
            q.push(node->left);
            q.push(node->right);
        } else {
            return false;
        }
    }

    return true;
}

int main() {
    int N;
    cin >> N;

    vector<int> preOrder(N), inOrder(N);
    for (int i = 0; i < N; i++) {
        cin >> preOrder[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> inOrder[i];
    }

    Node* root = buildTree(preOrder, inOrder, 0, N - 1, 0, N - 1);
    if (isPerfect(root)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}

This code first reads the input for the tree and then builds the tree. After that, it checks if the tree is a perfect binary tree. The `isPerfect` function uses a BFS approach to check if all internal nodes have exactly two children. It assumes that the BFS will reach all nodes with exactly two children at the same depth. If it can't reach all nodes, it returns false.