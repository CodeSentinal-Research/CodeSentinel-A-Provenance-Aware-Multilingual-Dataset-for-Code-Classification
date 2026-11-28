Here is the code for the problem:

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

Node* insertLevelOrder(Node* root, vector<int> arr, int i, int n) {
    if (i < n) {
        Node* temp = new Node(arr[i]);
        root = temp;
        root->left = insertLevelOrder(root->left, arr, 2 * i + 1, n);
        root->right = insertLevelOrder(root->right, arr, 2 * i + 2, n);
    }
    return root;
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int X, D;
    cin >> X >> D;
    Node* root = NULL;
    root = insertLevelOrder(root, arr, 0, N);
    cout << root->val << endl;
    return 0;
}

The `insertLevelOrder` function is a recursive function that creates a new node for each element in the array and assigns it to the root of the subtree rooted at the current node. The left and right children are then recursively assigned the subproblems.

In the main function, the input is read and processed to create the binary tree. The root of the tree is then inserted with the value and depth given in the problem.