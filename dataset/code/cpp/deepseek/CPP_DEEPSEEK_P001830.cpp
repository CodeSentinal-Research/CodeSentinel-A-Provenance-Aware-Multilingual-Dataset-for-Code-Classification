Here is the C++ code for the problem:

#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    int left;
    int right;
};

vector<int> keys;

void storeKeys(Node node, int x) {
    if (node.data > x) {
        keys.push_back(node.data);
    }
    if (node.left != -1) {
        storeKeys(Node{node.left, -1, -1}, x);
    }
    if (node.right != -1) {
        storeKeys(Node{node.right, -1, -1}, x);
    }
}

int findSmallestGreater(int x) {
    keys.clear();
    storeKeys(Node{0, -1, -1}, x);
    if (keys.empty()) {
        return -1;
    }
    return *min_element(keys.begin(), keys.end());
}

int main() {
    int N, x;
    cin >> N;
    vector<Node> tree(N);
    for (int i = 0; i < N; i++) {
        int data, left, right;
        cin >> data >> left >> right;
        tree[i] = Node{data, left, right};
    }
    cin >> x;
    int result = findSmallestGreater(x);
    if (result == -1) {
        cout << "NONE" << endl;
    } else {
        cout << result << endl;
    }
    return 0;
}

This code reads the size of the tree and the values of the tree nodes from the standard input. It then reads the value of X from the standard input. The `findSmallestGreater` function finds the smallest key greater than X and returns it, or "NONE" if there is no such key. The `storeKeys` function is a recursive function that stores all keys in a vector. The main function reads the values of N, tree, and X from the standard input, and prints the result of `findSmallestGreater`.