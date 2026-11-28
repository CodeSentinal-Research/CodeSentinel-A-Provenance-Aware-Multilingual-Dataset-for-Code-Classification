Here is the C++ code for the problem:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int key;
    int left, right;
};

const int MAXN = 100005;
int N;
Node node[MAXN];
int idx;

int build(int l, int r) {
    if (l > r) return 0;
    int m = l + r >> 1;
    node[m] = {node[m].key, 0, 0};
    int d = build(l, m - 1);
    int rd = build(m + 1, r);
    node[m].right = rd;
    return d + 1;
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> node[i].key;
    }
    for (int i = 1; i <= N; ++i) {
        if (node[i].key > node[2 * i].key && node[i].key > node[2 * i + 1].key) {
            cout << "INVALID";
            return 0;
        }
    }
    idx = 1;
    build(1, N);
    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        if (node[i].right) {
            ans += node[i].right - i + 1;
        }
    }
    cout << ans;
    return 0;
}

This code first reads the number of nodes and the keys of the nodes from the input. It then checks if the tree is a valid complete binary search tree. If the tree is not valid, it prints "INVALID". If the tree is valid, it builds the complete binary search tree and then calculates the number of nodes that need to be inserted to make the tree complete. The number of insertions is printed to the output.