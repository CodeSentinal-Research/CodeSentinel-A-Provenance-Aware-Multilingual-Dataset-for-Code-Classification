Here is the Python code for the problem.

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


def remove_duplicate_nodes(head):
    if head is None:
        return None

    current = head

    while current.next is not None:
        if current.data == current.next.data:
            current.next = current.next.next
        else:
            current = current.next

    return head


def create_linked_list(arr):
    if not arr:
        return None

    head = Node(arr[0])
    current = head

    for data in arr[1:]:
        node = Node(data)
        current.next = node
        current = current.next

    return head


def print_linked_list(head):
    if head is None:
        print('None')
        return

    current = head

    while current is not None:
        print(current.data, end=' ')
        current = current.next

    print()


def main():
    arr = [1, 2, 2, 3, 4, 4, 4, 5, 5]
    head = create_linked_list(arr)
    head = remove_duplicate_nodes(head)
    print_linked_list(head)


if __name__ == "__main__":
    main()

In this code, `Node` is a class representing a node in the linked list. It has two attributes: `data` (data to be stored in the node) and `next` (reference to the next node in the list).

The `remove_duplicate_nodes` function is responsible for iterating over the list and removing consecutive duplicate nodes. It does this by comparing each node's data with the next node's data. If they are the same, it skips over the next node; otherwise, it moves the current node to the next node.

The `create_linked_list` function is responsible for creating a linked list from an array of integers. It takes an array of integers as input and creates a linked list with the integers.

The `print_linked_list` function is responsible for printing the contents of a linked list.

In the `main` function, an array of integers is created, the array is used to create a linked list, the linked list is passed to `remove_duplicate_nodes` to remove consecutive duplicate nodes, and the modified linked list is printed.