#include <iostream>
#include <unordered_set>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int val): val(val), left(NULL), right(NULL) {}
};

Node* buildBST(int arr[], int start, int end) {
    if (start > end) return NULL;
    int mid = (start + end) / 2;
    Node* root = new Node(arr[mid]);
    root->left = buildBST(arr, start, mid - 1);
    root->right = buildBST(arr, mid + 1, end);
    return root;
}

bool findPair(Node* root, int sum, unordered_set<int>& nodes) {
    if (nodes.find(sum - root->val) != nodes.end()) {
        return true;
    }
    nodes.insert(root->val);
    if (root->left && findPair(root->left, sum, nodes)) {
        return true;
    }
    if (root->right && findPair(root->right, sum, nodes)) {
        return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int sum;
    cin >> sum;
    Node* root = buildBST(arr, 0, n - 1);
    unordered_set<int> nodes;
    if (findPair(root, sum, nodes)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
This code reads the number of nodes N, and the values of the nodes, and the sum K. It then builds a binary search tree from the given array and checks if there exists two distinct nodes whose values sum to K. The result is printed in the standard output.