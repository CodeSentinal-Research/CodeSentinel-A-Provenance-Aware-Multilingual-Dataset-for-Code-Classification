Sure, here is the Python code for the problem.

class Node:
    def __init__(self, data=None, next=None, prev=None):
        self.data = data
        self.next = next
        self.prev = prev

def reverse(head):
    if head is None:
        return None

    current = head
    while True:
        next_node = current.next
        if next_node is head:
            break
        current.next = current.prev
        current.prev = next_node
        next_node.prev = current
        next_node.next = current
        current = next_node
    head.prev = current
    current.next = head
    head = current
    return head

def create_list(arr):
    if len(arr) == 0:
        return None

    head = Node(arr[0])
    current = head
    for data in arr[1:]:
        node = Node(data)
        current.next = node
        node.prev = current
        current = node
    current.next = head
    head.prev = current
    return head

def print_list(head):
    if head is None:
        return

    current = head
    while True:
        print(current.data, end=' ')
        current = current.next
        if current == head:
            break
    print()

def main():
    arr = [1, 2, 3, 4, 5]
    head = create_list(arr)
    print_list(head)
    head = reverse(head)
    print_list(head)

if __name__ == "__main__":
    main()

In this code, we first define the `Node` class to create new nodes. We then define the `reverse` function, which reverses a circular doubly linked list. We use three pointers to track the current node, the next node, and the head node. The function first checks if the head node is `None`, and if so, returns `None`. It then enters a loop where it breaks if the next node is the head node. In each iteration of the loop, it swaps the `next` and `prev` pointers for the current node, and updates the next and prev pointers for the next node. Finally, it sets the new head of the reversed list and returns it.

The `create_list` function creates a new circular doubly linked list from an array. It takes an array of integers and creates a new node for each integer. It then sets the `next` pointer for each node to the next node in the list, and the `prev` pointer for each node to the previous node in the list. Finally, it returns the head node.

The `print_list` function prints the data of each node in a list. It takes a head node and enters a loop that prints the data of each node until it reaches the head node. It then prints an empty line to finish the list.

The `main` function creates a list of integers, prints the list, reverses the list, and prints the reversed list.