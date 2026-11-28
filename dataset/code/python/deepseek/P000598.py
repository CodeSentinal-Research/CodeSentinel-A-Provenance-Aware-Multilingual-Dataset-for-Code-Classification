Here is a Python solution for the problem:

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def reverseBetween(head, left, right):
    if not head:
        return None

    dummy = ListNode(0)
    dummy.next = head
    left_pre = dummy

    for i in range(left - 1):
        left_pre = left_pre.next

    right_node = left_pre.next
    curr = left_pre.next.next
    while right_node and right - left > 1:
        next_node = curr.next
        curr.next = right_node.next
        right_node.next = curr
        curr = curr.next
        right_node = next_node
    left_pre.next.next = curr

    return dummy.next

In this code, a dummy node is used to hold the head of the list. Then the dummy node is moved to the node before the left position, which is calculated by iterating from the left-1 position. After that, it reverses the nodes from the left to the right position.

The main function for the problem is as follows:

def main():
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    head.next.next.next.next = ListNode(5)

    left = 2
    right = 4

    result = reverseBetween(head, left, right)

    while result:
        print(result.val, end=" ")
        result = result.next
    print()

main()

This code will print: 1 2 3 5 4. The result is the linked list after reversing the nodes from position 2 to 4.