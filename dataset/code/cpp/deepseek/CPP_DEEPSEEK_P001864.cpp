#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int key;
    int left, right;
};

const int N = 2e5 + 5;
int n, root, ans;
Node nodes[N];

void dfs(int u, int p = -1) {
    if (nodes[u].left != -1) dfs(nodes[u].left, u);
    if (p != -1) {
        ans = max(ans, u - p);
    }
    if (nodes[u].right != -1) dfs(nodes[u].right, u);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        nodes[i].key = i + 1;
        nodes[i].left = nodes[i].right = -1;
    }
    if (n == 1) {
        cout << 0;
        return 0;
    }
    root = 1;
    ans = 0;
    dfs(root);
    cout << ans;
    return 0;
}
This code first sets up a structure to hold the information about the nodes of the tree. It then defines a DFS function to find the maximum search cost. In the DFS function, if a node's left child is not -1, it recursively calls the DFS function on the left child. If the node is not the root and it's not the left child of the parent, it updates the maximum search cost. If the node's right child is not -1, it recursively calls the DFS function on the right child.
The main function first reads the number of nodes and then initializes the maximum search cost. It then sets up the root of the tree and calls the DFS function to find the maximum search cost. The result is then printed.