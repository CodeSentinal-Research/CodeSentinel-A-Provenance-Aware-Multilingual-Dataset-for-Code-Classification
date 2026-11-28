Here is the C++ code for the problem:

#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void findSuccessor(TreeNode* root, int target) {
    queue<pair<TreeNode*, bool>> q;
    q.push({root, false});

    TreeNode* prev = nullptr;
    while(!q.empty()) {
        auto node = q.front();
        q.pop();

        if (node.second) {
            if (prev && prev->val == target) {
                if (node.first->left) {
                    cout << node.first->left->val << endl;
                    return;
                } else if (node.first->right) {
                    cout << node.first->right->val << endl;
                    return;
                }
            } else {
                if (node.first->left) {
                    prev = node.first->left;
                    q.push({node.first->left, true});
                } else if (node.first->right) {
                    prev = node.first->right;
                    q.push({node.first->right, true});
                }
            }
        } else {
            prev = node.first;
            if (node.first->left) {
                q.push({node.first->left, false});
            }
            if (node.first->right) {
                q.push({node.first->right, false});
            }
        }
    }
    cout << "None" << endl;
}

int main() {
    int n;
    cin >> n;

    vector<TreeNode*> nodes(n);
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        nodes[i] = new TreeNode(val);
    }

    int target;
    cin >> target;

    for(int i = 0; i < n - 1; i++) {
        nodes[i]->left = nodes[i + 1];
        nodes[i]->right = nullptr;
    }

    nodes[n - 1]->left = nullptr;
    nodes[n - 1]->right = nullptr;

    findSuccessor(nodes[0], target);

    for(int i = 0; i < n; i++) {
        delete nodes[i];
    }

    return 0;
}

This code firstly reads the number of nodes and their values. Then it builds the binary tree by creating `TreeNode` objects and connecting them left and right. After the binary tree is constructed, it finds the successor of the target node. If there is no successor, it prints "None".