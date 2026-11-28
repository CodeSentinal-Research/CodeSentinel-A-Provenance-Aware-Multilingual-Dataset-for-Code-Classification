Here is the Python code:

class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random

def clone_list(head: 'Node') -> 'Node':
    node_map = {}

    def helper(node):
        if node is None:
            return None
        if node in node_map:
            return node_map[node]
        new_node = Node(node.val)
        node_map[node] = new_node
        new_node.next = helper(node.next)
        new_node.random = helper(node.random)
        return new_node

    return helper(head)
In this code, a dictionary `node_map` is used to store the cloned nodes and return the corresponding node when a node is needed. The `helper` function is a recursive helper function which takes a node and returns its clone if it exists in the map, otherwise, it creates a new node with the same value and adds it to the map.

The input for the main function is the head of the linked list and the output is the head of the cloned linked list. The `clone_list` function is called with the head of the linked list as the argument.

For example, if you have the following linked list:

1 -> 2 -> 3

Then the `clone_list` function will be called with the head of this list:

head = Node(1)
head.next = Node(2)
head.random = Node(3)

Then `clone_list(head)` will return the head of the cloned list:

1 -> 2 -> 3