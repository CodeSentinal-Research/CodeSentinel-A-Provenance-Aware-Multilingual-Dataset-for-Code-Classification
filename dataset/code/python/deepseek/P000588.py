class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random

class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        if not head:
            return None

        nodes = {}

        new_node = Node(head.val)
        nodes[id(head)] = new_node

        node = head.next
        new_node.next = node
        while node:
            if node.next:
                n = node.next
                if n not in nodes:
                    nodes[id(n)] = Node(n.val)
                new_node.next.next = nodes[id(n)]
                new_node.next = new_node.next.next
            if node.random:
                n = node.random
                if n not in nodes:
                    nodes[id(n)] = Node(n.val)
                new_node.random = nodes[id(n)]
            node = node.next

        return new_node