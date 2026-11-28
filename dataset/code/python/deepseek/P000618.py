class Node:
    def __init__(self, x: int, prev: 'Node' = None, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.prev = prev
        self.next = next
        self.random = random

def cloneDLL(head: 'Node') -> 'Node':
    node_map = {}

    def _clone(node):
        if node is None:
            return None
        if node in node_map:
            return node_map[node]

        cloned = Node(node.val)
        node_map[node] = cloned

        cloned.next = _clone(node.next)
        cloned.prev = _clone(node.prev)

        return cloned

    return _clone(head)
The code above defines a doubly linked list Node class and a `cloneDLL` function. The `cloneDLL` function uses a hash map to store the cloned nodes. The `_clone` helper function is a recursive helper function that clones a node and its next and prev pointers. The `cloneDLL` function returns the head of the cloned list.

Note: This solution assumes that the input is a valid doubly linked list. If the input is invalid (e.g., a list of Nones), the code will raise an error. You may want to add additional error checking code to handle such cases depending on your specific requirements.