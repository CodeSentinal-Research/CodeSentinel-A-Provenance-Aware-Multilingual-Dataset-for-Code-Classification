class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def removeDuplicates(head):
    if head is None:
        return None
    current = head
    while current.next is not None:
        if current.val == current.next.val:
            current.next = current.next.next
        else:
            current = current.next
    return head

The function `removeDuplicates` receives the head of an unsorted linked list as input and modifies it to remove duplicate values. It uses a pointer `current` to traverse the linked list.

For each node in the list, it compares the value of the current node with the next node's value.

If the current node's value is equal to the next node's value, it skips the next node (removes the duplicate). Otherwise, it moves to the next node in the list.

This process continues until all duplicates have been removed. The function then returns the head of the linked list, which is the original head if all values were unique.