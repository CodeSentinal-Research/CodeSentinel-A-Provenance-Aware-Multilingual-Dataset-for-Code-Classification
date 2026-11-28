def check_sum_tree(n, tree):
    def get_subtree_sum(node):
        if node is None:
            return 0
        left_sum = get_subtree_sum(node.left)
        right_sum = get_subtree_sum(node.right)
        if left_sum != right_sum:
            return None
        return left_sum + node.val

    root_sum = get_subtree_sum(tree)
    return root_sum is not None and root_sum == sum(get_subtree_sum(node) for node in tree.children)

class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def main():
    n = int(input().strip())
    nodes = [Node(int(input().strip())) for _ in range(n)]
    nodes_map = {val: node for node in nodes}
    for _ in range(n):
        parent, left, right = input().strip().split()
        parent_node = nodes_map[int(parent)]
        if left:
            parent_node.left = nodes_map[int(left)]
        if right:
            parent_node.right = nodes_map[int(right)]
    print('YES' if check_sum_tree(n, nodes[0]) else 'NO')

if __name__ == '__main__':
    main()