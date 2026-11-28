#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int val) : key(val), left(NULL), right(NULL) {}
};

Node* createBSTFromAncestor(vector<vector<int>>& mat, int start, int end, Node* root) {
    if (start > end) {
        return NULL;
    }

    int mid = (start + end) / 2;

    root = new Node(mat[mid][0]);

    root->left = createBSTFromAncestor(mat, start, mid - 1, root->left);
    root->right = createBSTFromAncestor(mat, mid + 1, end, root->right);

    return root;
}

void levelOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << temp->key << " ";

        if (temp->left != NULL) {
            q.push(temp->left);
        }

        if (temp->right != NULL) {
            q.push(temp->right);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    Node* root = NULL;
    root = createBSTFromAncestor(mat, 0, n - 1, root);

    levelOrder(root);

    return 0;
}
This code will create a binary search tree from a given ancestor matrix and then print its elements in level order. Please note that this code assumes that the ancestor matrix is a full binary tree. If the matrix is not a full binary tree, then the result will be an IMPOSSIBLE message.