def count_internal_nodes(root):
    if root is None:
        return 0

    count = 0
    if root.left or root.right:
        count += 1

    count += count_internal_nodes(root.left)
    count += count_internal_nodes(root.right)

    return count

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def create_tree(nodes):
    if nodes is None:
        return None

    root = TreeNode(nodes.pop(0))
    current_nodes = [root]

    while nodes:
        node = nodes.pop(0)
        if node is not None:
            current_node = current_nodes.pop(0)
            if node.left:
                current_node.left = TreeNode(node.left)
                current_nodes.append(current_node.left)
            if node.right:
                current_node.right = TreeNode(node.right)
                current_nodes.append(current_node.right)

    return root

def main():
    n = int(input().strip())
    nodes = list(map(int, input().strip().split()))
    root = create_tree(nodes)
    print(count_internal_nodes(root))

if __name__ == "__main__":
    main()