Here is the Python code that solves the problem:

class Node:
    def __init__(self, x):
        self.val = x
        self.next = None
        self.prev = None

def rotateDoublyLinkedList(head, k):
    if head is None:
        return None

    last = head
    while last.next:
        last = last.next

    last.next = head
    head.prev = last
    tail = head
    while tail.next != head:
        tail = tail.next

    head = head
    tail.next = None

    head = rotate(head, k)

    tail.next = head
    head.prev = tail

    return head

def rotate(head, k):
    k = k % len_node(head)
    cur = head
    for _ in range(k):
        cur = cur.next
    cur_next = cur.next
    cur.next = None
    cur_next.prev = None
    return cur_next

def len_node(node):
    count = 0
    while node is not None:
        count += 1
        node = node.next
    return count

The above code creates a doubly linked list and then rotates it by k steps counterclockwise. The `rotateDoublyLinkedList` function first performs the last step of the list cutting operation to rotate it. Then, it calls the `rotate` function to rotate the list, and finally, it reattaches the list to make it a circular list.

The `rotate` function gets the node to be rotated and the number of steps to be made. It changes the next of the node to None and then the previous of the next node to None. It then moves to the next node the number of steps and returns the next node.

The `len_node` function gets the head of the list and returns the number of nodes in the list. It uses a loop to count the number of nodes in the list.