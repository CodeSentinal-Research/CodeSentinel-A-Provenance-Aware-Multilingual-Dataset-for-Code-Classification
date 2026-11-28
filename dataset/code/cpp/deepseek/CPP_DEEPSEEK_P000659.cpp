#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printLinkedListInReverseOrder(ListNode* head) {
    stack<int> s;
    ListNode* current = head;

    while (current != NULL) {
        s.push(current->val);
        current = current->next;
    }

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}

int main() {
    int n;
    cin >> n;

    ListNode* head = NULL;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        ListNode* node = new ListNode(value);
        node->next = head;
        head = node;
    }

    printLinkedListInReverseOrder(head);

    return 0;
}