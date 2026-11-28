Here is a simple implementation of the ordered dictionary using linked list in C++.

#include <iostream>
#include <unordered_map>

using namespace std;

class Node {
public:
    int key;
    int val;
    Node *next, *prev;
    Node(int key, int val) : key(key), val(val) {
        next = prev = nullptr;
    }
};

class OrderedDictionary {
private:
    Node *head, *tail;
    unordered_map<int, Node *> mp;
public:
    OrderedDictionary() : head(nullptr), tail(nullptr) {}

    ~OrderedDictionary() {
        while (head) {
            Node *tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    void put(int key, int val) {
        if (mp.find(key) != mp.end()) {
            mp[key]->val = val;
        } else {
            Node *node = new Node(key, val);
            if (head == nullptr) {
                head = tail = node;
            } else {
                tail->next = node;
                node->prev = tail;
                tail = node;
            }
            mp[key] = node;
        }
    }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            return mp[key]->val;
        }
        return -1;
    }

    void remove(int key) {
        if (mp.find(key) != mp.end()) {
            Node *node = mp[key];
            if (node->prev)
                node->prev->next = node->next;
            else
                head = node->next;
            if (node->next)
                node->next->prev = node->prev;
            else
                tail = node->prev;
            delete node;
            mp.erase(key);
        }
    }

    int firstKey() {
        if (head == nullptr)
            return -1;
        return head->key;
    }

    int lastKey() {
        if (tail == nullptr)
            return -1;
        return tail->key;
    }

    int nextKey(int key) {
        Node *node = mp[key];
        if (node->next == nullptr)
            return -1;
        return node->next->key;
    }

    int previousKey(int key) {
        Node *node = mp[key];
        if (node->prev == nullptr)
            return -1;
        return node->prev->key;
    }
};

int main() {
    int q;
    cin >> q;
    OrderedDictionary dict;
    while (q--) {
        string op;
        int key, val;
        cin >> op;
        if (op == "put") {
            cin >> key >> val;
            dict.put(key, val);
        } else if (op == "get") {
            cin >> key;
            cout << dict.get(key) << "\n";
        } else if (op == "remove") {
            cin >> key;
            dict.remove(key);
        } else if (op == "first") {
            cout << dict.firstKey() << "\n";
        } else if (op == "last") {
            cout << dict.lastKey() << "\n";
        } else if (op == "prev") {
            cin >> key;
            cout << dict.previousKey(key) << "\n";
        } else if (op == "next") {
            cin >> key;
            cout << dict.nextKey(key) << "\n";
        }
    }
    return 0;
}

This program first reads the number of operations, then for each operation it reads the operation type and then the corresponding parameters. It then performs the operation on the dictionary and prints the result.