#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int v, Node *l = nullptr, Node *r = nullptr) : val(v), left(l), right(r) {}
};

int countPaths(Node* root, int k) {
    if (root == nullptr) {
        return 0;
    }

    queue<pair<Node*, int>> q;
    q.push({root, 0});

    vector<int> pathSums(21, 0);
    pathSums[0] = 1;

    while (!q.empty()) {
        auto [node, sum] = q.front();
        q.pop();

        sum += node->val;

        if (pathSums.count(sum - k)) {
            if (sum == k) {
                pathSums[sum]++;
            }

            if (node->left != nullptr) {
                q.push({node->left, sum});
            }
            if (node->right != nullptr) {
                q.push({node->right, sum});
            }
        } else {
            pathSums[sum]++;

            if (node->left != nullptr) {
                q.push({node->left, sum});
            }
            if (node->right != nullptr) {
                q.push({node->right, sum});
            }
        }
    }

    int sum = 0;
    for (int i = 0; i <= 20; i++) {
        if (pathSums[i] > 1) {
            sum += pathSums[i] - 1;
        }
    }

    return sum;
}

int main() {
    int N;
    cin >> N;
    vector<int> nodes(N);
    for (int i = 0; i < N; i++) {
        cin >> nodes[i];
    }

    vector<Node*> tree(N, nullptr);
    for (int i = 0; i < N; i++) {
        if (2 * i + 1 < N) {
            tree[i] = new Node(nodes[i], tree[2 * i + 1], tree[2 * i + 2]);
        } else {
            tree[i] = new Node(nodes[i]);
        }
    }

    int K;
    cin >> K;
    cout << countPaths(tree[0], K) << endl;

    for (auto node : tree) {
        delete node;
    }

    return 0;
}