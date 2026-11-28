#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int val): val(val), left(NULL), right(NULL) {}
};

bool isPalindrome(Node* root) {
    queue<Node*> q;
    q.push(root);
    bool isOdd = false;
    while(!q.empty()) {
        Node* cur = q.front(); q.pop();
        if ((isOdd && (cur->val != root->val)) || (!isOdd && cur->val != root->val)) {
            return false;
        }
        isOdd ^= true;
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> vals(n);
    for(int i = 0; i < n; i++) {
        cin >> vals[i];
    }
    vector<Node*> nodes(n+1);
    for(int i = 0; i < n; i++) {
        Node* node = new Node(vals[i]);
        if(i < n/2) {
            nodes[i/2] = node;
            nodes[i/2]->left = nodes[i];
        } else {
            nodes[i/2-1]->right = node;
        }
    }
    if(isPalindrome(nodes[0])) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
This code reads the number of nodes, the node values, and the binary tree from the standard input. It then constructs the binary tree and checks if the sequence of node values at every level forms a palindrome. If it does, it prints "YES"; otherwise, it prints "NO".

Please note that the order of input for the binary tree construction depends on the problem constraints. For example, in the provided code, we assume that the parent-child relationships are filled in a top-down manner. If the binary tree is filled in a bottom-up manner, the construction part can be modified accordingly.