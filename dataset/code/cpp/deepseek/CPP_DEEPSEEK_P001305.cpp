#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int data;
    int freq;
    Node* left;
    Node* right;
};

struct compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

Node* newNode(int data, int freq) {
    Node* temp = new Node();
    temp->data = data;
    temp->freq = freq;
    temp->left = temp->right = NULL;
    return temp;
}

Node* buildHuffmanTree(int data[], int freq[], int size) {
    priority_queue<Node*, vector<Node*>, compare> pq;

    for (int i = 0; i < size; i++) {
        pq.push(newNode(data[i], freq[i]));
    }

    while (pq.size() != 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        int total = left->freq + right->freq;
        pq.push(newNode(total, left->freq + right->freq));
    }

    return pq.top();
}

int calculateCost(Node* root, string str, int &cost) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL) {
        cout << "Char: " << root->data << "  Huffman Code: " << str << "\n";
        cost += root->freq * str.length();
        return root->freq;
    }

    int totalCost = 0;
    if (root->left) {
        totalCost += calculateCost(root->left, str + "0", cost);
    }

    if (root->right) {
        totalCost += calculateCost(root->right, str + "1", cost);
    }

    return totalCost;
}

int main() {
    int N;
    cin >> N;

    int* data = new int[N];
    int* freq = new int[N];

    for (int i = 0; i < N; i++) {
        cin >> data[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> freq[i];
    }

    Node* root = buildHuffmanTree(data, freq, N);

    int cost = 0;
    calculateCost(root, "", cost);

    cout << "Minimum encoding cost: " << cost << "\n";

    return 0;
}