Here is the Python code for the given problem.

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def partition(head, x):
    if not head:
        return None

    less_head, less_tail = None, None
    greater_head, greater_tail = None, None

    while head:
        if head.val < x:
            if less_head is None:
                less_head = head
                less_tail = head
            else:
                less_tail.next = head
                less_tail = head
        else:
            if greater_head is None:
                greater_head = head
                greater_tail = head
            else:
                greater_tail.next = head
                greater_tail = head
        head = head.next

    if less_tail:
        less_tail.next = greater_head
        return less_head
    else:
        return greater_head

This function takes a linked list and an integer x as input, and returns the head of the partitioned linked list. It uses two pointers (less_head, less_tail, greater_head, greater_tail) to store the nodes less than x and greater than or equal to x separately. For each node in the linked list, if the value is less than x, it is added to the less_head and less_tail. If the value is greater than or equal to x, it is added to the greater_head and greater_tail. After processing all nodes, the less nodes are linked together with the greater nodes. The function returns the head of the partitioned linked list.