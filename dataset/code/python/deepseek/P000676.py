Here is the Python code for the problem. 

class ListNode:
    def __init__(self, val=0, next=None, child=None):
        self.val = val
        self.next = next
        self.child = child

def merge(l1, l2):
    if l1 and l2:
        if l1.val < l2.val:
            l1.next = merge(l1.next, l2)
            return l1
        else:
            l2.next = merge(l1, l2.next)
            return l2
    return l1 or l2

def flatten(head):
    if head is None:
        return None
    pseudo_head = ListNode(0)
    pseudo_head.next = head
    prev, curr = None, head
    while curr:
        if curr.child:
            next_node = curr.next
            curr.next = curr.child
            curr.child = None
            prev.next = curr.next
            curr.next.next = flatten(next_node)
            prev = curr.next
        else:
            prev = curr
            curr = curr.next
    return pseudo_head.next
In this code, we first define a class `ListNode` to represent the nodes of the linked list. Then we define a function `merge` to merge two sorted linked lists. The `flatten` function is the main function that takes the head of the input list, creates a new head, and then iterates through the input list. If a node has a child, it takes the next node from the child list, sets the next of the current node to the child list, removes the child from the current node, and then recursively calls `flatten` on the next node. If the current node does not have a child, it simply moves the current node to the next one. Finally, it returns the new head of the flattened list.