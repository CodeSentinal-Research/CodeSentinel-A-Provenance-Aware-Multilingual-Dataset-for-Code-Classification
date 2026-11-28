Here is the complete code:

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool isPalindrome(ListNode* head) {
    vector<int> values;
    ListNode* current = head;

    while (current != NULL) {
        values.push_back(current->val);
        current = current->next;
    }

    for (int i = 0; i < values.size() / 2; i++) {
        if (values[i] != values[values.size() - 1 - i]) {
            return false;
        }
    }

    return true;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);

    cout << isPalindrome(head) << endl;  

    return 0;
}

In this code, a linked list is first created, and then the `isPalindrome` function is used to check if the linked list is a palindrome. The function first collects all values from the linked list into a vector, then it compares the vector with its reverse. If all values match, it returns true, otherwise it returns false. The `main` function demonstrates this by creating a linked list with 5 nodes, and then calling `isPalindrome` on this list. The result is printed to the console.