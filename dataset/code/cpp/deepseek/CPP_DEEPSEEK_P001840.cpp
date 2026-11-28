#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left, *right;
    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

void serialize(Node* root, string& str) {
    if (root == nullptr) {
        str += "null,";
        return;
    }
    str += to_string(root->data) + ",";
    serialize(root->left, str);
    serialize(root->right, str);
}

Node* deserialize(string data) {
    queue<string> q;
    size_t start = 0, end;
    while ((end = data.find(',', start)) != string::npos) {
        q.push(data.substr(start, end - start));
        start = end + 1;
    }
    if (q.front() == "null") {
        q.pop();
        return nullptr;
    }
    Node* root = new Node(stoi(q.front()));
    q.pop();
    while (!q.empty()) {
        if (q.front() == "null") {
            q.pop();
            root->right = nullptr;
        } else {
            root->right = new Node(stoi(q.front()));
            q.pop();
        }
        if (q.empty()) break;
        if (q.front() == "null") {
            q.pop();
            root->left = nullptr;
        } else {
            root->left = new Node(stoi(q.front()));
            q.pop();
        }
    }
    return root;
}

int main() {
    int N;
    cin >> N;
    cin.ignore();
    string data;
    getline(cin, data); 
    Node* root = nullptr;
    for (int i = 0; i < N; i++) {
        if (i == 0) {
            root = new Node(stoi(data));
        } else {
            Node* temp = new Node(stoi(data));
            if (i % 2 == 0) {
                root->left = temp;
            } else {
                root->right = temp;
            }
        }
        getline(cin, data);
    }
    string serialized;
    serialize(root, serialized);
    cout << serialized << endl;
    Node* reconstructed = deserialize(serialized);
    while (reconstructed != nullptr) {
        cout << reconstructed->data << " ";
        Node* temp = reconstructed;
        reconstructed = reconstructed->right;
        if (temp == reconstructed) break;
        reconstructed->left = nullptr;
    }
    cout << endl;
    return 0;
}