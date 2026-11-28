Here is the C++ code:

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapNodes(ListNode* head, int x, int y) {
    if (x == y) return head;

    ListNode *xPrev = nullptr, *xNode = nullptr, *yPrev = nullptr, *yNode = nullptr;
    for (ListNode *node = head; node; node = node->next) {
        if (node->val == x) xPrev = node, xNode = node;
        if (node->val == y) yPrev = node, yNode = node;
    }

    if (!xPrev && !yPrev) return head;

    if (xPrev) xPrev->next = yNode;

    if (yPrev) yPrev->next = xNode;

    swap(xNode->next, yNode->next);

    return head;
}
This code will swap nodes with values x and y in a linked list if they exist in the list. If either value is not present, the list will remain unchanged.