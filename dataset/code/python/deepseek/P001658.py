class Node:
    def __init__(self, value=None):
        self.value = value
        self.left = None
        self.right = None

def build_tree(nodes):
    if not nodes:
        return None

    node_value = nodes.pop(0)
    if node_value is None:
        return None

    node = Node(node_value)
    node.left = build_tree(nodes)
    node.right = build_tree(nodes)

    return node

def find_nodes(root, target, k):
    queue = [(root, 0)]
    visited = set()

    while queue:
        node, dist = queue.pop(0)

        if node is not None:
            if dist == k and node.value == target:
                print(node.value)
            visited.add(node.value)
            queue.extend((node.left, dist + 1), (node.right, dist + 1))

def main():
    N = int(input())
    nodes = list(map(int, input().split()))
    target, k = map(int, input().split())

    root = build_tree(nodes)
    find_nodes(root, target, k)

if __name__ == "__main__":
    main()