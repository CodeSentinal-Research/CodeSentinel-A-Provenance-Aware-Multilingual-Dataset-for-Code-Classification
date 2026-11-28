#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int findMaxValue(ListNode* head) {
    if(head == NULL) return -1;

    int maxVal = head->val;
    ListNode* current = head->next;

    while(current != NULL) {
        if(current->val > maxVal) {
            maxVal = current->val;
        }
        current = current->next;
    }

    return maxVal;
}

int main() {



    return 0;
}