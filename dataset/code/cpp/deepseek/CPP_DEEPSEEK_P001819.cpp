#include <iostream>
#include <queue>
#include <utility>

using namespace std;

struct Node {
    int key;
    int leftChild;
    int rightChild;
    int parent;
};

int size = 0;
Node nodes[100001];

void addNode(int key, int parent) {
    nodes[size].key = key;
    nodes[size].leftChild = -1;
    nodes[size].rightChild = -1;
    nodes[size].parent = parent;
    size++;
}

int findKeyRank(int key) {
    queue<pair<int, int> > q;
    q.push({0, 0});
    while (!q.empty()) {
        int nodeIndex = q.front().first;
        int rank = q.front().second;
        q.pop();
        if (nodes[nodeIndex].key == key) {
            return rank;
        }
        if (nodes[nodeIndex].leftChild != -1) {
            q.push({nodes[nodeIndex].leftChild, rank + 1});
        }
        if (nodes[nodeIndex].rightChild != -1) {
            q.push({nodes[nodeIndex].rightChild, rank + 1});
        }
    }
    return -1;
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int parent;
        cin >> parent;
        if (i == 0) {
            addNode(parent, -1);
        } else {
            addNode(parent, size - 1);
        }
    }
    int X;
    cin >> X;
    cout << findKeyRank(X) << "\n";
    return 0;
}