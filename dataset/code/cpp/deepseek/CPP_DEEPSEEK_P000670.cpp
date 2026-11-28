Here is the required C++ code for the problem:

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int sum(ListNode* head) {
    int sum = 0;
    while (head != NULL) {
        sum += head->val;
        head = head->next;
    }
    return sum;
}

int main() {
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);

    head->next = second;
    second->next = third;

    cout << sum(head);  

    return 0;
}

In this code, we create a `ListNode` struct to represent a node in the linked list. We then define a `sum` function that takes a pointer to the head of the linked list as input and returns the sum of all node values. Inside the `sum` function, we use a while loop to traverse the linked list, adding the value of each node to the sum. Once we've traversed the entire linked list, we return the sum.

In the `main` function, we create a linked list with three nodes, and print the sum of the nodes in this list.