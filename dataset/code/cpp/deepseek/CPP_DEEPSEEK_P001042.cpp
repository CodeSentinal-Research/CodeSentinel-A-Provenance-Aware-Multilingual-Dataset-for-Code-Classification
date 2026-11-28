#include <iostream>
#include <vector>
using namespace std;

void findLeafNodes(int root, int n, vector<int> &tree) {
    if (root > n) {
        return;
    }
    if (root * 2 > n) {
        cout << tree[root] << " ";
    } else {
        findLeafNodes(root * 2, n, tree);
        findLeafNodes(root * 2 + 1, n, tree);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> tree(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> tree[i];
    }
    findLeafNodes(1, n, tree);
    return 0;
}