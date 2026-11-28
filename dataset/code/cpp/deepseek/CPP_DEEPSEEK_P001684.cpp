Here's the code for the problem:

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};

Node* newNode(int val) {
    Node* node = new Node();
    node->value = val;
    node->left = node->right = nullptr;
    return node;
}

Node* buildTree(vector<int>& inorder, vector<int>::iterator itr, int start, int end, unordered_map<int, Node*>& map) {
    if (itr == inorder.end() || start > end)
        return nullptr;

    Node* node = newNode(inorder[*itr]);
    map[inorder[*itr]] = node;

    int index = find(inorder.begin(), inorder.end(), preorder[*pt]) - inorder.begin();
    node->left = buildTree(inorder, itr + 1, start, index - 1, map);
    node->right = buildTree(inorder, itr + index + 1, index + 1, end, map);
    return node;
}

int main() {
    int N;
    cin >> N;
    vector<int> preorder(N), inorder(N);

    for (int i = 0; i < N; i++)
        cin >> preorder[i];

    for (int i = 0; i < N; i++)
        cin >> inorder[i];

    unordered_map<int, Node*> map;
    Node* root = buildTree(inorder, inorder.begin(), 0, N - 1, map);

    int a, b;
    cin >> a >> b;

    if (map[a]->left == map[b] && map[a]->right == map[b])
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
This C++ solution uses a map to store the nodes of the tree in the inorder traversal of the tree, then it checks if both nodes are in the same subtree of the tree.