class Node:
    def __init__(self, val, prev=None, next=None):
        self.val = val
        self.prev = prev
        self.next = next

def reverseEvenLength(head):
    if head is None or head.next is None:
        return head

    slow, fast = head, head.next
    prev_slow, prev_fast = head, head.next

    while fast and fast.next and fast.next.next:
        slow.next = fast.next
        fast.next.prev = slow
        slow.prev = fast
        slow = fast.next
        fast.next = slow.next
        fast.next.prev = slow
        fast = fast.next.next
        if fast.next is None:
            break
        slow.next = fast.next
        fast.next.prev = slow

    if slow.next is not None:
        prev_slow.prev = slow.next
        slow.next.prev = prev_slow
        prev_slow.next = slow.next.next
        if slow.next.next is not None:
            slow.next.next.prev = prev_slow

    return head