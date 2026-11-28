Sure, I've written a Python solution for the problem. This solution uses a two-pointer approach. We create two dummy nodes, `even` and `odd`. We then iterate through the original linked list, and for each node, we append it to the appropriate dummy node.

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def oddEvenList(head):
    if not head:
        return None
    
    even = head.next
    odd = head
    head.next = even

    new_head = odd
    while odd.next and odd.next.next:
        even.next = odd.next.next
        odd.next.next = even.next

        odd = odd.next
        even = even.next

    odd.next = even
    return new_head

In the main function, you can create the linked list like this:

def main():
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    head.next.next.next.next = ListNode(5)

    new_head = oddEvenList(head)

    while new_head:
        print(new_head.val)
        new_head = new_head.next

if __name__ == "__main__":
    main()

In this code, the `ListNode` class is used to define a node in the linked list. The `main` function creates a linked list and calls the `oddEvenList` function, then prints the rearranged linked list.