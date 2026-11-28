Here is the C++ code:

#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteEveryKthNode(ListNode* head, int k) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev = &dummy;
    ListNode* curr = head;
    
    while(curr) {
        prev->next = curr->next;
        delete curr;
        curr = prev->next;
        k--;
        if(k==0) {
            k = -1; 
        }
    }
    
    return dummy.next;
}

int main(int argc, char* argv[]) {
    if(argc != 4) {
        cout << "Usage: ./program <n> <Linked List> <k>" << endl;
        return 1;
    }

    int n = atoi(argv[1]);
    ListNode* head = new ListNode(atoi(argv[2]));
    ListNode* temp = head;
    for(int i = 3; i <= n; i += 2) {
        temp->next = new ListNode(atoi(argv[i]));
        temp = temp->next;
    }

    int k = atoi(argv[n + 1]);
    ListNode* result = deleteEveryKthNode(head, k);

    while(result) {
        cout << result->val << ' ';
        result = result->next;
    }
    cout << endl;

    while(head) {
        ListNode* temp = head->next;
        delete head;
        head = temp;
    }

    return 0;
}
This program receives the number of nodes in the linked list, the linked list itself, and the value to delete every k-th node as arguments. It creates a new linked list using the given linked list and deletes every k-th node from it. Finally, it prints the modified linked list.