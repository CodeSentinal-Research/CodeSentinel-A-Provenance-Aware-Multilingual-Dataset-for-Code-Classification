Here's the Python code:

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def search(head: ListNode, target: int) -> bool:
    curr = head
    while curr:
        if curr.val == target:
            return True
        curr = curr.next
    return False

You can call this function with a head node and a target value like this:

head = ListNode(1)
head.next = ListNode(2)
head.next.next = ListNode(3)
head.next.next.next = ListNode(4)
head.next.next.next.next = ListNode(5)

print(search(head, 3))  
print(search(head, 6))  

In this code, we create a `ListNode` class to represent each node in the linked list. We define a function, `search`, that takes a head node and a target value as arguments, and returns `True` if the target is found in the linked list, and `False` otherwise.

The `search` function works by starting from the head node of the linked list, and checking if the current node's value is equal to the target. If it is, the function returns `True`. Otherwise, it moves to the next node, and checks again. This continues until it either finds a node with the target value (`True` is returned), or it reaches the end of the linked list (`False` is returned).