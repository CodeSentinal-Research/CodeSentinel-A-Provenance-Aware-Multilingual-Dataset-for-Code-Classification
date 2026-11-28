Sure, here is the Python code for the given problem.

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def reverseEvenLengthGroup(head):
    group_start = ListNode(0)
    group_start.next = head
    group = group_start
    reverse_group = None
    length = 0

    while head:
        tail = head
        count = 1
        while count < 500 and tail.next:
            tail = tail.next
            count += 1
        if count % 2 == 0:
            reverse_group, head = reverse(group_start.next, head, tail)
            if length:
                group.next = reverse_group
                group = group.next
            else:
                group_start.next = reverse_group
                group = group_start
            length += count
        else:
            group.next = head
            head = tail.next
            group = group.next

    return group_start.next

def reverse(start, a, b):
    prev = b
    current = a
    while start != b:
        next_node = current.next
        current.next = prev
        prev = current
        current = next_node
    start.next = prev
    return prev, current

This code defines a linked list node class `ListNode`. The `reverseEvenLengthGroup` function is where the main logic of the problem is implemented. It first initializes the necessary variables and pointers. Then it enters a loop where it iterates over each node in the linked list and reverses the nodes in even-sized groups. When it encounters a node with odd size, it simply skips to the next node. The `reverse` function is a helper function that reverses a group of nodes.