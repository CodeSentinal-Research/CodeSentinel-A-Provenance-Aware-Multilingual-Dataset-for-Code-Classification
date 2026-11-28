Here is the Python code for the problem.

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def deleteDuplicates(head):
    if head is None:
        return None

    current = head
    while current.next is not None:
        if current.val == current.next.val:
            current.next = current.next.next
        else:
            current = current.next

    return head

def main():
    node1 = ListNode(1)
    node2 = ListNode(2)
    node3 = ListNode(3)
    node4 = ListNode(4)
    node5 = ListNode(4)
    node6 = ListNode(5)

    node1.next = node2
    node2.next = node3
    node3.next = node4
    node4.next = node5
    node5.next = node6

    result = deleteDuplicates(node1)

    while result is not None:
        print(result.val)
        result = result.next

if __name__ == "__main__":
    main()

In this code, we define a `ListNode` class for the singly-linked list nodes. In the `deleteDuplicates` function, we iterate over the linked list, checking if the current value is equal to the next value. If it is, we skip the next node by setting the next pointer of the current node to the node after the next node. Otherwise, we move on to the next node.

The `main` function creates a linked list with the values 1, 2, 3, 4, 4, 5, and calls the `deleteDuplicates` function to remove duplicates. It then prints the values of the linked list after the duplicates have been removed.