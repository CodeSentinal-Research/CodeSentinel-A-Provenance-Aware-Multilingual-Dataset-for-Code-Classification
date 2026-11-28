#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int data): data(data), left(NULL), right(NULL) {}
};

Node* newNode(int data) {
    return new Node(data);
}

Node* buildTree(vector<int> &inorder, vector<int> &postorder, int &index, int start, int end) {
    if (start > end) {
        return NULL;
    }

    int currVal = postorder[index--];
    Node* node = newNode(currVal);

    if (start == end) {
        return node;
    }

    int iIndex = find(inorder.begin(), inorder.end(), currVal) - inorder.begin();

    node->right = buildTree(inorder, postorder, index, iIndex + 1, end);
    node->left = buildTree(inorder, postorder, index, start, iIndex - 1);

    return node;
}

void printLevelOrder(Node *root) {
    if (root == NULL) return;

    queue<Node *> q;
    q.push(root);

    while (q.empty() == false) {
        Node *node = q.front();
        cout << node->data << " ";
        q.pop();

        if (node->left != NULL) {
            q.push(node->left);
        }

        if (node->right != NULL) {
            q.push(node->right);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> inorder(n), postorder(n);

    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> postorder[i];
    }

    int index = n - 1;
    Node *root = buildTree(inorder, postorder, index, 0, n - 1);

    printLevelOrder(root);

    return 0;
}