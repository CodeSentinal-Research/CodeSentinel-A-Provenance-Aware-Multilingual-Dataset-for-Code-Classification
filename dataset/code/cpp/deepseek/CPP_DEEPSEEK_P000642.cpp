Here is the C++ code for the problem:

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* insertNode(ListNode* head, int position, int value) {
    ListNode* newNode = new ListNode(value);
    ListNode* current = head;

    if(position == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        for(int i = 0; i < position - 1; i++) {
            if(current->next == NULL)
                return head;
            current = current->next;
       
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    return head;
}

This code first creates a new node with the given value and position. Then, it traverses to the position where the new node should be inserted. If the position is 0, the new node is added at the start of the list, otherwise, it is added at the end of the list.