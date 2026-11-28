Here's a Python solution for the given problem:

class Node:
    def __init__(self, x):
        self.val = x
        self.next = None
        self.prev = None

def reverse(head, k):
    current = head

    while current:
        group = current
        count = 0
        while group and count < k:
            next_node = group.next
            group.next, group.prev = group.prev, group.next
            group = next_node
            count += 1

        if current and current.next:
            current.next.prev = current
        current = current.next
        if current and current.next:
            current.next.prev = current
        else:
            break

    return head

n = int(input())
values = list(map(int, input().split()))

head = None
current = None
for value in values:
    node = Node(value)
    if current is None:
        head = current = node
    else:
        current.next = node
        node.prev = current
        current = node

k = int(input())
head = reverse(head, k)

while head:
    print(head.val, end=' ')
    head = head.next

In this solution, we define a `Node` class to create a new node with a given value and pointers to the next and previous nodes. We then create a `reverse` function that takes the head of the doubly linked list and the group size as inputs. In this function, we iterate through the list and for each node, we reverse the group of size k. We also need to connect the reversed group with the next group using previous and next pointers.

The main function takes the number of nodes n and a list of values, creates a doubly linked list from these values, and calls the `reverse` function with the head of the list and the group size as inputs. The modified doubly linked list is then printed.