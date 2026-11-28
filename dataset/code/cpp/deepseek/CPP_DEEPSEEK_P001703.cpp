#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

class Tree {
public:
    Tree(int n) {
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            nodes.push_back(new Node(val));
        }
        for (int i = 0; i < n; i++) {
            int left, right;
            cin >> left >> right;
            if (left != -1) nodes[left]->left = nodes[i];
            if (right != -1) nodes[right]->right = nodes[i];
        }
    }

    int maxDiff() {
        int maxDiff = 0;
        maxDifference(nodes[0], nodes[0]->value, nodes[0]->value, maxDiff);
        return maxDiff;
    }

private:
    void maxDifference(Node* node, int min, int max, int& diff) {
        if (node == nullptr) return;
        if (node->value > max) {
            max = node->value;
        }
        if (node->value < min) {
            min = node->value;
        }
        diff = max(diff, abs(max - min));
        maxDifference(node->left, min, max, diff);
        maxDifference(node->right, min, max, diff);
    }

    vector<Node*> nodes;
};

int main() {
    int n;
    cin >> n;
    Tree tree(n);
    cout << tree.maxDiff() << endl;
    return 0;
}