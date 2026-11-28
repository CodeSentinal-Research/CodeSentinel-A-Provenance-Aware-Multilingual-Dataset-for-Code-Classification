class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key

def insert(node, key):
    if node is None:
        return Node(key)
    else:
        if node.val < key:
            node.right = insert(node.right, key)
        else:
            node.left = insert(node.left, key)
    return node

def find_ceiling(root, key):
    ceiling = None
    while root is not None:
        if root.val == key:
            return root.val
        elif root.val < key:
            ceiling = root.val
            root = root.right
        else:
            root = root.left
    return "None" if ceiling is None else ceiling

def bst_from_list(lst):
    if not lst:
        return None
    nodes = [Node(lst[0])]
    for num in lst[1:]:
        insert(nodes[0], num)
    return nodes[0]

def main():
    N = int(input().strip())
    lst = list(map(int, [input().strip() for _ in range(N)]))
    X = int(input().strip())
    root = bst_from_list(sorted(lst))
    print(find_ceiling(root, X))

if __name__ == "__main__":
    main()