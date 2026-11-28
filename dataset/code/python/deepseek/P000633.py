class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def detectAndRemoveLoop(head):
    if head is None or head.next is None:
        return head

    slow = head
    fast = head.next

    while slow != fast:
        slow = slow.next
        fast = fast.next.next

        if slow == fast:
            break

    if slow != fast:
        return head

    slow = None
    while head != slow:
        next_node = head.next
        head.next = slow
        slow = head
        head = next_node

    return None