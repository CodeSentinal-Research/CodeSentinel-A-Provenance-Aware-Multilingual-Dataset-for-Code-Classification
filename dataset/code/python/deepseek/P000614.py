Here is the Python code to solve the problem:

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def swapKthNode(head, k):
    if head is None or k <= 0:
        return head

    first = head
    second = head

    for _ in range(k - 1):
        if first is not None:
            first = first.next

    while first.next is not None:
        second = second.next
        first = first.next

    if first != second:
        first.val, second.val = second.val, first.val

    return head

def print_list(head):
    while head is not None:
        print(head.val, end=' ')
        head = head.next
    print()

def main():
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    head.next.next.next.next = ListNode(5)

    print("Original List:")
    print_list(head)

    head = swapKthNode(head, 3)

    print("After Swap:")
    print_list(head)

if __name__ == '__main__':
    main()

This code first defines a helper class `ListNode` to create a node of the linked list.

Then, the `swapKthNode` function swaps the k-th node from the beginning and the k-th node from the end of the linked list.

In the test part, a linked list is created and the `print_list` function is used to print the linked list. The result is printed after the swapping operation.