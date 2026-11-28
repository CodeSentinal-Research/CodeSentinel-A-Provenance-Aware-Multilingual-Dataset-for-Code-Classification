Here is the C++ code for the given problem:

#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* Solution(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr || l2 == nullptr) {
        return nullptr;
    }

    ListNode* intersect = nullptr;

    while (l1 != l2) {
        if (l1 == nullptr) {
            l1 = l2;
        } else {
            l1 = l1->next;
        }

        if (l2 == nullptr) {
            l2 = l1;
        } else {
            l2 = l2->next;
        }
    }

    return l1;
}

int main() {
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);

    l1->next = new ListNode(3);
    l2->next = new ListNode(4);

    ListNode* intersectNode = Solution(l1, l2);

    if (intersectNode != nullptr) {
        cout << intersectNode->val << endl;
    } else {
        cout << "No intersection" << endl;
    }

    return 0;
}

This code first checks if either of the two lists are null. If either is, it sets the intersect list to nullptr and returns it. 

Then, it enters a while loop that runs until the two lists are equal. Inside the loop, it moves the pointers in the lists one step at a time. If one list reaches the end, it sets the pointer to the other list. If the other list reaches the end, it sets the pointer to the first list. 

Finally, it returns the intersection node.