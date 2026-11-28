#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int val) : val(val), next(nullptr) {}
};

Node* skipMNnodes(Node* head, int M, int N) {
    Node* dummy = new Node(0);
    dummy->next = head;
    Node* prev = dummy;
    Node* curr = head;
    
    while(curr) {
        for(int i = 1; i < M && curr; ++i)
            curr = curr->next;
        if(curr)
            for(int i = 0; i < N && curr; ++i)
                curr = curr->next;
        if(curr)
            prev->next = curr->next;
        prev = curr;
        curr = curr->next;
    }
    return dummy->next;
}

void printList(Node* head) {
    while(head) {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << '\n';
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    printList(head);
    head = skipMNnodes(head, 2, 2);
    printList(head);
    return 0;
}