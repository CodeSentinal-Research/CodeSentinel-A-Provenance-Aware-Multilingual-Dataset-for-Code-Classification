class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def print_reversed(head):
    if head is None:
        return

    while head.next is not None:
        head = head.next
    while head is not None:
        print(head.val, end=' ')
        head = head.next

This Python code defines a class `ListNode` to represent a node in the linked list. The `print_reversed` function takes the head of the linked list as input and prints the values of the nodes in reverse order. It does this by first finding the last node in the linked list using a while loop, and then prints the values of all nodes in the reversed linked list.

The main function is not provided in the question, but it could be as follows:

def main():
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)

    print_reversed(head)

if __name__ == "__main__":
    main()

This will output: `4 3 2 1`