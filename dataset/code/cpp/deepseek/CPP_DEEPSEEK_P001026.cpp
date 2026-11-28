Sure, here is a C++ solution for the problem:

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isComplete(vector<int> &parent, int n) {
    queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        if (leftChild < n && parent[leftChild] != -1) {
            q.push(leftChild);
        }

        if (rightChild < n && parent[rightChild] != -1) {
            q.push(rightChild);
       
        }
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> parent(n, -1);

    for (int i = 0; i < n; i++) {
        int node;
        cin >> node;

        if (node != -1) {
            parent[node] = i;
        }
    }

    if (isComplete(parent, n)) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
This C++ solution uses a breadth-first search (BFS) approach to verify if the given tree is a complete binary heap. The idea is to visit every node in the tree and check if the current node is a leaf node or not. If any non-leaf node is visited, we know the tree is not a complete binary heap. If all nodes are visited, the tree is a complete binary heap.