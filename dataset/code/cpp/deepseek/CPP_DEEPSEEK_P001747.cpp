Here is the C++ code for the problem:

#include <iostream>
#include <queue>
#include <utility>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int maxNodes(Node* root) {
    if(root == NULL)
        return 0;
        
    int leftMax = maxNodes(root->left);
    int rightMax = maxNodes(root->right);
    
    return 1 + max(leftMax, rightMax);
}

int main() {
    int N;
    cin >> N;

    Node* root = NULL;

    for(int i = 0; i < N; i++) {
        int data;
        cin >> data;
        Node* temp = newNode(data);

        if(i == 0) {
            root = temp;
        } else {
            queue<pair<Node*, int>> q;
            q.push({root, 1});

            while(!q.empty()) {
                pair<Node*, int> p = q.front();
                q.pop();

                if(p.first->left == NULL && p.first->right == NULL) {
                    if(p.second < maxNodes(root)) {
                        maxNodes(root) = p.second;
                        cout << p.second;
                        break;
                    }
                }

                if(p.first->left != NULL)
                    q.push({p.first->left, p.second + 1});

                if(p.first->right != NULL)
                    q.push({p.first->right, p.second + 1});
            }
        }
    }

    return 0;
}

The `maxNodes` function is used to find the maximum number of leaf nodes in the binary tree. The `main` function is used to input the binary tree and find the level with the maximum number of leaf nodes.