Here is a Python solution for the given problem using Floyd's cycle-finding algorithm (also known as the "tortoise and the hare" algorithm).

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def hasCycle(head):
    if head is None:
        return False
    slow = head
    fast = head.next

    while slow != fast:
        if fast is None or fast.next is None:
            return False
        slow = slow.next
        fast = fast.next.next

    return True

This code first checks if the head of the linked list is None. If it is, then it returns False, because there is no cycle in an empty linked list.

Then it initializes slow and fast pointers to the head of the linked list.

In each iteration of the while loop, the slow pointer moves one step at a time while the fast pointer moves two steps at a time. If there is a cycle (that is, if fast is not None and fast.next is not None), the fast pointer will eventually meet the slow pointer, indicating a cycle.

If the fast pointer hits None or None (the end of the linked list), then the function returns False, because there is no cycle.

If the fast pointer doesn't hit None or None (the end of the linked list), then the function returns True, indicating a cycle.