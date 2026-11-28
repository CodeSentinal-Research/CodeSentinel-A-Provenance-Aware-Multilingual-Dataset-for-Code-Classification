Here's the Python code for the given problem:

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def removeElements(head, val):
    dummy = ListNode(0)
    dummy.next = head

    prev, curr = dummy, head

    while curr:
        if curr.val == val:
            prev.next = curr.next
        else:
            prev = curr
        curr = curr.next

    return dummy.next

And the main function for handling input:

def main():
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(2)
    head.next.next.next.next = ListNode(4)

    val = 2

    head = removeElements(head, val)

    while head:
        print(head.val)
        head = head.next

if __name__ == "__main__":
    main()

This will print the linked list:

1
3
4

The linked list after removing all occurrences of 2: 1 -> 3 -> 4.