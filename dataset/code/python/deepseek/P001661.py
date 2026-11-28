def can_fold(root):
    def helper(node1, node2):
        if node1 is None and node2 is None:
            return True
        elif node1 is None or node2 is None:
            return False
        else if node1.value != node2.value:
            return False
        return helper(node1.left, node2.right) and helper(node1.right, node2.left)
    return helper(root, root)


class TreeNode:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


def create_tree(nodes):
    root = None
    nodes = [node.split() for node in nodes]
    nodes = [(int(node[0]), int(node[1])) for node in nodes]
    nodes.append((0, 0))
    nodes.append((0, 0))
    index = {(x, y): index for index, (x, y) in enumerate(nodes)}
    for (x, y), index in sorted(index.items()):
        node = TreeNode(index)
        if (x, y) == (0, 0):
            root = node
        else:
            parent, direction = divmod(index, 2)
            if direction == 0:
                nodes[parent].left = node
            else:
                nodes[parent].right = node
    return root


def main():
    N = int(input().strip())
    nodes = [input().strip() for _ in range(N)]
    root = create_tree(nodes)
    print('YES' if can_fold(root) else 'NO')


if __name__ == '__main__':
    main()