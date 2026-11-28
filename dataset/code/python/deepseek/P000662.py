Here is the Python code to solve the problem:

class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None

def reverse_k_nodes(head, k):
    if not head or k <=1:
        return head

    prev = None
    curr = head
    while k and curr:
        next_node = curr.next
        if prev:
            curr.next = prev
        else:
            head = curr
        prev = curr
        curr = next_node

    if prev:
        prev.next = curr
    return head


def main():
    input_list = [1, 2, 3, 4, 5, 6, 7, 8, 9]
    k = 3

    head = Node(input_list[0])
    curr = head
    for num in input_list[1:]:
        curr.next = Node(num)
        curr = curr.next

    head = reverse_k_nodes(head, k)

    while head:
        print(head.data, end=' ')
        head = head.next
    print()


if __name__ == "__main__":
    main()

This code first defines a `Node` class for the linked list nodes. Then, it defines a function `reverse_k_nodes` that takes as input a linked list and a number `k`. It creates a new linked list by reversing the first `k` nodes in the original list. The function returns the head of the new list.

The `main` function creates a linked list with the input values, reverses the first `k` nodes, and then prints the new list.