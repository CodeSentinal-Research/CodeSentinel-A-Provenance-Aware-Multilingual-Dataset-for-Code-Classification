#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<vector<int>> tree(N);
    for (int i = 0; i < N - 1; i++) {
        int parent, child;
        cin >> parent >> child;
        tree[parent - 1].push_back(child - 1);
    }

    for (int i = 0; i < Q; i++) {
        int node, k;
        cin >> node >> k;

        vector<int> ancestors;
        for (int j = 0; j < k; j++) {
            int anc;
            cin >> anc;
            ancestors.push_back(anc - 1);
        }

        for (int j = 0; j < k; j++) {
            if (ancestors[j] >= ancestors.size()) {
                cout << -1 << endl;
                break;
            }
            else {
                cout << ancestors[j] << endl;
                break;
            }
        }
    }

    return 0;
}
This program reads a rooted tree and Q queries, then it prints the Kth ancestor of the specified node. If no such ancestor exists, it prints -1.