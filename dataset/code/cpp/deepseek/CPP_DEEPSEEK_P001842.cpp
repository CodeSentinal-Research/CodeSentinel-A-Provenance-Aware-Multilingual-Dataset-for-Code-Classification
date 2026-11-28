Here is a C++ code for the problem. This code uses the inorder traversal method to get the sorted union of keys from both BSTs.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
public:
    int data;
    Node* left, * right;
    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

Node* SortedArrayToBST(vector<int>& arr, int start, int end) {
    if (start > end) {
        return nullptr;
    }

    int mid = (start + end) / 2;

    Node* root = new Node(arr[mid]);

    root->left = SortedArrayToBST(arr, start, mid - 1);

    root->right = SortedArrayToBST(arr, mid + 1, end);

    return root;
}

Node* FindUnion(Node* root1, Node* root2) {
    vector<int> in1, in2;

    if (root1 != nullptr) {
        Node* temp = root1;
        while (temp) {
            in1.push_back(temp->data);
            temp = temp->right;
        }
    }

    if (root2 != nullptr) {
        Node* temp = root2;
        while (temp) {
            in2.push_back(temp->data);
            temp = temp->right;
        }
    }

    in1.insert(in1.end(), in2.begin(), in2.end());

    sort(in1.begin(), in1.end());

    return SortedArrayToBST(in1, 0, in1.size() - 1);
}

int main() {
    int n1, n2;

    cin >> n1;

    Node* root1 = nullptr;
    for (int i = 0; i < n1; i++) {
        int data;
        cin >> data;
        root1 = FindUnion(root1, new Node(data));
    }

    cin >> n2;

    Node* root2 = nullptr;
    for (int i = 0; i < n2; i++) {
        int data;
        cin >> data;
        root2 = FindUnion(root2, new Node(data));
    }

    Node* temp = root2;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->right;
    }

    return 0;
}

This code first reads the number of nodes in the first and second trees, and then reads the data of the nodes. It then creates the BSTs and calculates the union of the trees.

Please note that the input format of your problem statement is not clear. The input format of the problem is described in the problem statement. The problem statement describes the input as follows:

- The first line contains N₁, the number of nodes in the first BST.
- The next N₁ lines, the descriptions of the first BST.
- The following line contains N₂, the number of nodes in the second BST.
- The next N₂ lines, the descriptions of the second BST.

This code assumes that the input is in this format. If the input format is different, you would need to modify the code to handle the input in the correct format.