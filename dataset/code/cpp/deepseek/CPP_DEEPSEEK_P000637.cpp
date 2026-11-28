#include <iostream>
#include <unordered_map>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    if(head == nullptr || head->next == nullptr) return head;
    
    std::unordered_map<int, int> count;
    count[head->val] = 1;
    ListNode* current = head;
    
    while(current->next != nullptr) {
        if(count.find(current->next->val) != count.end()) {
            current->next = current->next->next;
        } else {
            count[current->next->val] = 1;
            current = current->next;
        }
    }
    return head;
}

int main() {
    return 0;
}

This code defines a `ListNode` struct for singly linked list nodes and a function `deleteDuplicates` that takes the head of the list as input and returns the head of the modified list. 

The `unordered_map` is used to keep track of the count of each node's value. If the count of a node's value is more than 1, the node is removed. Otherwise, the count is incremented. 

In the `main` function, you can provide the input and call the `deleteDuplicates` function to get the output.