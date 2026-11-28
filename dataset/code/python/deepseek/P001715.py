def count_full_nodes(root):
    if root is None:
        return 0
    count = 0
    if root.left and root.right:
        count += 1
    count += count_full_nodes(root.left)
    count += count_full_nodes(root.right)
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
    queue = [root]
    while queue:
        node = queue.pop(0)
        if nodes:
            node.left = TreeNode(nodes.pop(0))
            queue.append(node.left)
        if nodes:
            node.right = TreeNode(nodes.pop(0))
            queue.append(node.right)
    return root

def main():
    n = int(input().strip())
    nodes = list(map(int, input().strip().split()))[:n]
    root = create_tree(nodes)
    print(count_full_nodes(root))

if __name__ == "__main__":
    main()