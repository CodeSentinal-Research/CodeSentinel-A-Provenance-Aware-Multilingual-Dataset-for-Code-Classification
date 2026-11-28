#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
};

int sumOddLevelNodes(Node* root) {
    if (!root) {
        return 0;
    }

    queue<Node*> q;
    q.push(root);
    int sum = 0;
    int level = 0;

    while (!q.empty()) {
        int size = q.size();
        while (size > 0) {
            Node* node = q.front();
            q.pop();

            if (level % 2 == 1) {
                sum += node->val;
            }

            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
           
            }

            size--;
        }
        level++;
    }

    return sum;
}

int main() {
    return 0;
}