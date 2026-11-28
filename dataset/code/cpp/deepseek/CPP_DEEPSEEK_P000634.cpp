#include <iostream>
#include <unordered_map>

struct ListNode {
    int val;
    ListNode *next;
    ListNode *random;
    ListNode(int x) : val(x), next(NULL), random(NULL) {}
};

ListNode* cloneList(ListNode* head) {
    if (head == nullptr) return nullptr;
    
    std::unordered_map<ListNode*, ListNode*> nodeMap;
    ListNode* newHead = new ListNode(head->val);
    ListNode* curr = head->next;
    ListNode* prev = newHead;
    
    nodeMap[head] = newHead;
    
    while (curr != nullptr) {
        if (nodeMap.find(curr) == nodeMap.end()) {
            ListNode* newNode = new ListNode(curr->val);
            nodeMap[curr] = newNode;
        } else {
            newNode = nodeMap[curr];
        }
        
        prev->next = newNode;
        prev = newNode;
        curr = curr->next;
    }
    
    prev->next = nullptr;
    
    curr = head;
    prev = newHead;
    
    while (curr != nullptr) {
        if (curr->random != nullptr) {
            if (nodeMap.find(curr->random) == nodeMap.end()) {
                ListNode* newRandom = new ListNode(curr->random->val);
                nodeMap[curr->random] = newRandom;
            } else {
                newRandom = nodeMap[curr->random];
            }
            prev->random = newRandom;
        }
        prev = prev->next;
        curr = curr->next;
    }
    
    return newHead;
}