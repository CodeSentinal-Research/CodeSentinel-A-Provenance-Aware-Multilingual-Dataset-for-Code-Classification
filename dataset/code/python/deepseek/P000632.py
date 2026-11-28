Here is the Python code for the problem:

class Node:
    def __init__(self, x):
        self.val = x
        self.next = None
        self.prev = None

def reverse(head):
    if not head:
        return None

    cur = head
    while cur:
        next_node = cur.next
        cur.next = cur.prev
        cur.prev = next_node
        cur = next_node

    head = cur
    return head

def print_list(head):
    cur = head
    while cur:
        print(cur.val, end=" ")
        cur = cur.next
    print()

def main():
    n = int(input())
    arr = list(map(int, input().split()))
    nodes = [Node(val) for val in arr]

    for i in range(len(nodes) - 1):
        nodes[i].next = nodes[i + 1]
        nodes[i + 1].prev = nodes[i]

    head = nodes[0]
    print_list(head)

    head = reverse(head)
    print_list(head)

main()

In this code, we first define a Node class to represent each node in the doubly linked list. The reverse function iterates through the list, changing the next and prev pointers for each node, and finally returning the head of the reversed list. The print_list function is used for printing the values of the linked list. The main function reads the number of nodes and the values of the nodes, constructs the linked list, prints the original list, reverses the list and prints the reversed list.