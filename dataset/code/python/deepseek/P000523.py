Here is a Python solution for the given problem.

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def removeNodes(head):
    if head is None:
        return None

    max_val = head.val
    head.val = 0
    curr = head

    while curr.next:
        if curr.next.val >= max_val:
            max_val = curr.next.val
        curr = curr.next

    if curr.next is not None and curr.next.val >= max_val:
        max_val = curr.next.val
        curr.next = None

    return head

This code defines a ListNode class and a function `removeNodes` that takes the head of a linked list as input. If the head of the list is None, it returns None. Otherwise, it sets the max_val to the value of the head, and then sets the current node to the head.

The while loop then iterates over the list, updating max_val if a larger value is found. The loop also checks if the next node's value is greater than or equal to max_val, and if so, sets max_val to that value.

Finally, if a node's value is greater than or equal to max_val, and there is a next node, it sets the next node to None, effectively removing it.

The function returns the modified head of the list.

Input handling is not included in the code as it's a requirement of the problem statement. You can handle it in the main function by creating a linked list and passing its head to the `removeNodes` function.