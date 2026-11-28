class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

def insert_node(root, key):
    if root is None:
        return Node(key)
    else:
        if root.key < key:
            root.right = insert_node(root.right, key)
        else:
            root.left = insert_node(root.left, key)
    return root

def find_distance(root, target):
    visited = {target}
    queue = [(root, 0)]
    while queue:
        node, dist = queue.pop(0)
        if node.left and node.left not in visited:
            visited.add(node.left)
            queue.append((node.left, dist + 1))
        if node.right and node.right not in visited:
            visited.add(node.right)
            queue.append((node.right, dist + 1))
        if node.left is None and node.right is None:
            return dist

def find_closest_leaf(root, target):
    root = insert_node(root, target)
    distance = find_distance(root, target)
    return distance

def main():
    N = int(input())
    keys = list(map(int, input().split()))
    target = int(input())
    root = None
    for key in keys:
        root = insert_node(root, key)
    print(find_closest_leaf(root, target))

if __name__ == "__main__":
    main()