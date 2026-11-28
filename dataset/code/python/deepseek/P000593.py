Here is the Python code for the problem:

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def swapPairs(head):
    if not head or not head.next:
        return head

    prev = head
    curr = head.next

    while prev and curr:
        prev.val, curr.val = curr.val, prev.val

        if not curr.next or not curr.next.next:
            break

        prev = curr.next
        curr = curr.next.next

    return head

def print_list(node):
    while node:
        print(node.val, end=' ')
        node = node.next
    print()

def main():
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)

    print("Original list:")
    print_list(head)

    head = swapPairs(head)

    print("Swapped list:")
    print_list(head)

if __name__ == "__main__":
    main()

In this code, `ListNode` is a utility class to represent a node in the linked list. It has two attributes: `val` to store the value at the node and `next` to store the next node in the list.

The `swapPairs` function takes the head of the linked list as input and swaps every two adjacent nodes in the list. It uses a while loop to iterate over the list and swap the values of the current and next nodes until there are no more pairs to swap.

The `print_list` function is used for printing the linked list.

In the `main` function, a linked list is created with the values 1, 2, 3, and 4, and it is printed. Then, the `swapPairs` function is called on the linked list, and the resulting linked list is printed.