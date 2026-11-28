Here's a simple C++ code snippet that fulfills your requirements. This code uses a hash set to keep track of summed values, and only inserts nodes into the hash set if the current sum is not in the set.

#include <iostream>
#include <unordered_set>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeZeroSumSublists(ListNode* head) {
    ListNode dummy(0);
    dummy.next = head;
    int sum = 0;
    std::unordered_set<int> sumSet;
    while (head != nullptr) {
        sum += head->val;
        if (sum == 0) {
            head = head->next;
            continue;
        }
        if (sumSet.find(sum) != sumSet.end()) {
            ListNode* node = head;
            int tempSum = sum + node->val;
            while (tempSum != sum) {
                tempSum += node->next->val;
                node = node->next;
            }
            node->next = node->next->next;
        } else {
            sumSet.insert(sum);
        }
        head = head->next;
    }
    return dummy.next;
}

int main() {
    return 0;
}
This code will work if the input linked list only contains positive integers. If the list can contain negative numbers, you will need to adjust the sum calculation accordingly.