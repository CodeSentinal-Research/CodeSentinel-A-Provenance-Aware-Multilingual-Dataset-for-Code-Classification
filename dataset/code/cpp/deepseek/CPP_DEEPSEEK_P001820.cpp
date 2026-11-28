#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int x) : key(x), left(NULL), right(NULL) {}
};

void insert(Node* &root, int x) {
    if (root == NULL) {
        root = new Node(x);
    } else {
        if (root->key > x) {
            insert(root->left, x);
        } else {
            insert(root->right, x);
        }
    }
}

int findRank(Node* root, int &rank) {
    if (root == NULL) {
        return -1;
    }

    if (root->left != NULL) {
        int leftRank = 1 + findRank(root->left, rank);
        if (leftRank == rank) {
            return root->key;
        }
    }

    rank--;
    if (root->right != NULL) {
        int rightRank = findRank(root->right, rank);
        return rightRank;
    }

    return -1;
}

int main() {
    int n;
    cin >> n;

    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insert(root, x);
    }

    int rank;
    cin >> rank;
    rank--; 

    cout << findRank(root, rank) << endl;

    return 0;
}