Here is the C++ code for the problem:

#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* prev;
    Node* random;
    
    Node(int val) : val(val), next(NULL), prev(NULL), random(NULL) {}
};

Node* Solution(Node* head) {
    if(head == NULL) return NULL;
    
    unordered_map<Node*, Node*> map;
    Node* copy = new Node(head->val);
    map[head] = copy;
    head = head->next;
    
    while(head != NULL) {
        if(map.find(head) == map.end()) {
            Node* newNode = new Node(head->val);
            map[head] = newNode;
        }
        
        if(head->prev != NULL) {
            if(map.find(head->prev) == map.end()) {
                Node* newNode = new Node(head->prev->val);
                map[head->prev] = newNode;
            }
            map[head]->prev = map[head->prev];
        }
        
        if(head->random != NULL) {
            if(map.find(head->random) == map.end()) {
                Node* newNode = new Node(head->random->val);
                map[head]->random = newNode;
            }
            map[head]->random = map[head->random];
        }
        
        if(map[head]->next == NULL) break;
        
        head = head->next;
    }
    
    return copy;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->prev = head->next->next;
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next-prev = head->next->next;
    head->next->next->next->next->next-next = new Node(7);
    head->next->next->next->next->next-next-prev = head->next->next;
    
    Node* copy = Solution(head);
    
    while(copy != NULL) {
        cout << copy->val << " ";
        copy = copy->next;
    }
    
    return 0;
}

This code first creates a copy of the original linked list, then it traverses the original list and the copy list simultaneously. For each node in the original list, it creates a new node in the copy list, and then it links the new node to the new node in the copy list. It also links the new node's previous and next pointers to the old node's corresponding new nodes.