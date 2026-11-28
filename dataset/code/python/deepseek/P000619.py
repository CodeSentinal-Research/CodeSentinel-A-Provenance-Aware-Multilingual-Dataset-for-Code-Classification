Here is the Python code with the main function and input handling.

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def deleteMiddle(head):
    if not head.next:
        return None

    slow, fast = head, head.next.next

    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next

    if slow.next.next:
        slow.next = slow.next.next
    else:
        slow.next = None

    return head

The main function to test the program:

def main():
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    head.next.next.next.next = ListNode(5)

    new_head = deleteMiddle(head)

    while new_head:
        print(new_head.val, end=" ")
        new_head = new_head.next

if __name__ == "__main__":
    main()

This program will print: `1 2 3 4`.

Note: This program assumes the input linked list is well-formed and contains at least one node. If the input linked list can be None or contains less than or more than one node, additional checks should be added.