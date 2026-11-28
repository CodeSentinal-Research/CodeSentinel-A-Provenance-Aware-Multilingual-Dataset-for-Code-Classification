def cloneGraph(node, visited=None):
    if visited is None:
        visited = set()

    if node in visited:
        return node

    visited.add(node)

    clone = Node(node.val, [])

    for neighbor in node.neighbors:
        clone.neighbors.append(cloneGraph(neighbor, visited))

    return clone

class Node:
    def __init__(self, val, neighbors):
        self.val = val
        self.neighbors = neighbors