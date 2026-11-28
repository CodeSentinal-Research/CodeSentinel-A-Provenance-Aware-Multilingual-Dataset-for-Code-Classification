#include <unordered_map>

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* random;
    Node(int _val) : val(_val), left(nullptr), right(nullptr), random(nullptr) {}
};

class Solution {
    std::unordered_map<Node*, Node*> cloned;

    Node* cloneStructure(Node* node) {
        if (!node) return nullptr;
        Node* copy = new Node(node->val);
        cloned[node] = copy;
        copy->left = cloneStructure(node->left);
        copy->right = cloneStructure(node->right);
        return copy;
    }

    void connectRandom(Node* node) {
        if (!node) return;
        if (node->random) {
            cloned[node]->random = cloned[node->random];
        }
        connectRandom(node->left);
        connectRandom(node->right);
    }
public:
    Node* copyRandomBinaryTree(Node* root) {
        if (!root) return nullptr;
        cloned.clear();
        Node* newRoot = cloneStructure(root);
        connectRandom(root);
        return newRoot;
    }
};