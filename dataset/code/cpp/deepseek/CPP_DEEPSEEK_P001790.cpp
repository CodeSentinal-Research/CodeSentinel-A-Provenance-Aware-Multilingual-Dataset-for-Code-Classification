#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};

int findMin(Node* root) {
    if (root == nullptr) {
        return INT_MAX; 
    }
    while (root->left != nullptr) {
        root = root->left;
    }
    return root->value;
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int value;
        cin >> value;
    }

    return 0;
}
This is the complete code with explanations.