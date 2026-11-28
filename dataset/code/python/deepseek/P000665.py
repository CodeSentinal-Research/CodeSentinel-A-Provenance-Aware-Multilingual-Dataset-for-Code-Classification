Here's the Python code for the problem:

class Node:
    def __init__(self, x):
        self.val = x
        self.next = None

def reverse_circular_linked_list(head):
    if not head:
        return None

    prev = head
    curr = head.next

    while curr != head:
        next_node = curr.next
        curr.next = prev
        prev = curr
        curr = next_node

    head.next = prev
    return prev

def create_circular_linked_list(arr):
    if not arr:
        return None

    head = Node(arr[0])
    curr = head

    for i in range(1, len(arr)):
        curr.next = Node(arr[i])
        curr = curr.next

    curr.next = head

    return head

def print_list(head):
    if not head:
        return

    curr = head
    while True:
        print(curr.val, end=" -> " if curr != head else "\n")
        curr = curr.next
        if curr == head:
            break

def main():
    arr = [1, 2, 3, 4, 5]
    head = create_circular_linked_list(arr)
    reversed_head = reverse_circular_linked_list(head)
    print_list(reversed_head)

if __name__ == "__main__":
    main()

This code will create a circular linked list with the given input, reverse the list, and print the reversed list. The `create_circular_linked_list` function is used to create the circular linked list, and the `reverse_circular_linked_list` function is used to reverse the list. The `print_list` function is used to print the list.