#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int val;
    int height;
    Node* next[1];

    Node(int val) {
        this->val = val;
        height = 1;
        next[0] = nullptr;
    }
};

class SkipList {
private:
    Node* head;

    Node* createNode(int val) {
        Node* node = new Node(val);
        return node;
    }

    int randomHeight() {
        int height = 1;
        while (rand() % 2 == 0 && height < log2(1.5)) height++;
        return height;
    }

    Node* searchNode(int val, Node* node) {
        while (node != nullptr && node->val != val) {
            if (node->val > val) node = node->next[0];
            else node = node->next[1];
        }
        return node;
    }

    void insertNode(int val, Node* node) {
        node->next[0] = node->next[1] = nullptr;
        if (head == nullptr || node->val < head->val) {
            node->height = 1;
            node->next[0] = head;
            head = node;
        } else {
            vector<Node*> update(max(0, (int)log2(1.5) - 1), nullptr);
            for (Node* temp = head; temp != nullptr; temp = temp->next[0]) {
                if (temp->val > val) update.push_back(temp);
                else update.push_back(temp->next[0]);
            }
            for (int i = 0; i < update.size(); ++i) {
                if (update[i] != nullptr && update[i]->val > val) update[i] = update[i]->next[0];
                else update[i] = update[i]->next[1];
            }
            if (update[0] == nullptr) {
                update[0] = node;
            } else {
                node->next[0] = update[0];
                if (update[1] != nullptr) {
                    update[1]->next[0] = node->next[1];
                    node->next[1] = update[1];
                } else {
                    node->next[1] = update[0]->next[1];
                    update[0]->next[1] = node;
                }
                node->height = randomHeight();
                update[0]->height = max(update[0]->height, node->height);
            }
        }
    }

    Node* eraseNode(int val, Node* node) {
        vector<Node*> update(max(0, (int)log2(1.5) - 1), nullptr);
        for (Node* temp = head; temp != nullptr; temp = temp->next[0]) {
            if (temp->val > val) update.push_back(temp);
            else update.push_back(temp->next[0]);
        }
        for (int i = 0; i < update.size(); ++i) {
            if (update[i] != nullptr && update[i]->val > val) update[i] = update[i]->next[0];
            else update[i] = update[i]->next[1];
        }
        if (update[0] != nullptr && update[0]->val == val) {
            update[0] = update[0]->next[0];
            for (int i = 0; i < update.size(); ++i) {
                if (update[i] != nullptr) {
                    if (update[i]->next[0] != nullptr) {
                        update[i]->next[1] = update[i]->next[1]->next[0];
                    }
                    delete update[i];
                }
            }
            while (update.size() > 0 && head->val <= val) {
                Node* temp = head;
                head = head->next[0];
                delete temp;
            }
        }
        return node;
    }

public:
    SkipList() {
        head = createNode(INT_MAX);
    }

    bool search(int val) {
        Node* node = searchNode(val, head);
        if (node != nullptr) cout << "Found " << val << "\n";
        else cout << "Not Found " << val << "\n";
        return node != nullptr;
    }

    void add(int val) {
        insertNode(val, createNode(val));
    }

    void erase(int val) {
        eraseNode(val, head);
    }
};

int main() {
    srand(time(0));
    SkipList skiplist;
    int q, val;
    char op;
    cin >> q;
    while (q--) {
        cin >> op >> val;
        if (op == 'a') {
            skiplist.add(val);
        } else if (op == 's') {
            skiplist.search(val);
        } else if (op == 'e') {
            skiplist.erase(val);
        }
    }
    return 0;
}
This C++ program creates a SkipList class with methods for searching, adding, and erasing elements. The search operation will print whether the element was found or not, while the add and erase operations will add and erase the element from the list, respectively. The operations are processed sequentially based on the input provided.