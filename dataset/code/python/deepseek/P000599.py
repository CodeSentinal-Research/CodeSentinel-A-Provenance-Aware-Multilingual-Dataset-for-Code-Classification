Here is the Python code for the problem.

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def deleteDuplicates(head):
    if head is None:
        return None
    dummy = ListNode(0)
    dummy.next = head
    current = dummy

    while head and head.next:
        if head.val == head.next.val:
            while head.next and head.val == head.next.val:
                head = head.next
            current.next = head.next
            head = current.next
        else:
            current = current.next
            head = head.next

    return dummy.next

This function works by creating a dummy node and a pointer current. The dummy node is used to ensure that the next node can always be accessed and the original head of the list is not lost. 

The loop continues until the end of the list is reached, and if the current node's value is the same as the next node's value, the while loop removes all duplicates from the list until the next node is not the same.

If the current node's value is not the same as the next node's value, the current pointer is moved one step to the next node.