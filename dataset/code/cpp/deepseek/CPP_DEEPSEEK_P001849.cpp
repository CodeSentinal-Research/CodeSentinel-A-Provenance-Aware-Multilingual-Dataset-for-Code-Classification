Here is the C++ code for your problem. This code is based on the fact that the height of a binary search tree is equivalent to the maximum depth of the binary tree.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> keys(n);
    for (int i = 0; i < n; i++) {
        cin >> keys[i];
    }

    sort(keys.begin(), keys.end());

    int maxDepth = 0;
    for (int i = 0; i < n; i++) {
        int depth = count(keys.begin(), keys.end(), keys[i]) - 1;
        maxDepth = max(maxDepth, depth);
    }

    cout << maxDepth << endl;

    return 0;
}

This code first reads the number of keys, and then the keys themselves. It then sorts the keys in ascending order.

For each key in the sorted keys, it calculates the depth of the subtree rooted at this key. The depth is the number of nodes on the path from the root to this node.

Finally, it finds the maximum depth among all the keys. This is the height of the resulting binary search tree.