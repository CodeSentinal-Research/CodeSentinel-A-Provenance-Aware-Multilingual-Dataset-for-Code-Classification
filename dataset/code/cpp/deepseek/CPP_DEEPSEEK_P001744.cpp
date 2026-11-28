Here is the code snippet for the problem:

#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int childCount;
    Node* child;
};

bool isInternalNodeOnly(Node* root, int& count) {
    if (root == nullptr) {
        return true;
    }

    if (root->childCount != 0) {
        return false;
    }

    count++;

    if (root->child != nullptr) {
        if (!isInternalNodeOnly(root->child, count)) {
            return false;
        }
    }

    return true;
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int childCount;
        cin >> childCount;

        vector<Node> nodes(childCount);
        for (int j = 0; j < childCount; j++) {
            cin >> nodes[j].childCount;
            nodes[j].child = nullptr;
        }

        if (isInternalNodeOnly(nodes[0].child, count)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}

This code reads the number of nodes and then for each node, it reads the number of children and if it is 0 then it's internal node. Then it checks whether all internal nodes have exactly one child or not. If all internal nodes do have exactly one child then it prints "YES" else it prints "NO".