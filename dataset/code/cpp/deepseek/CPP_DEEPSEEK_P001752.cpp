#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    int left, right, parent;
};

int main() {
    int n;
    cin >> n;
    vector<Node> tree(n + 1);
    vector<int> ancestors(n + 1);

    for (int i = 1; i <= n; i++) {
        tree[i].data = i;
        cin >> tree[i].left >> tree[i].right;
        if (tree[i].left != 0)
            tree[tree[i].left].parent = i;
        if (tree[i].right != 0)
            tree[tree[i].right].parent = i;
    }

    for (int i = 1; i <= n; i++) {
        int parent = tree[i].parent;
        if (parent == 0)
            ancestors[i] = 0;
        else if (parent == tree[parent].left)
            ancestors[i] = ancestors[parent] + 1;
        else
            ancestors[i] = ancestors[parent];
    }

    for (int i = 1; i <= n; i++)
        cout << ancestors[i] << endl;

    return 0;
}