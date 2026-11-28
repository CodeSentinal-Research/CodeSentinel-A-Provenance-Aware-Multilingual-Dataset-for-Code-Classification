def solve(root, parent_value):
    if not root:
        return True
    left_value = root.left.val if root.left else 0
    right_value = root.right.val if root.right else 0
    if root.val != left_value + right_value + parent_value:
        root.val = left_value + right_value + parent_value
        return False
    left_valid = solve(root.left, root.val)
    right_valid = solve(root.right, root.val)
    return left_valid and right_valid

def process_tree(root):
    if not root:
        return
    solve(root, 0)

def main():
    import sys
    N = int(sys.stdin.readline().strip())
    nodes = [sys.stdin.readline().strip().split() for _ in range(N)]
    nodes = [[int(y) for y in x] for x in nodes]
    nodes = [[nodes[i][0], nodes[i][1], nodes[i][2]] for i in range(N)]
    tree = [Node(val=v, left=None, right=None) for v in range(N)]
    for i, node in enumerate(tree):
        if nodes[i][1] != -1:
            node.left = tree[nodes[i][1]]
        if nodes[i][2] != -1:
            node.right = tree[nodes[i][2]]
    process_tree(tree[0])
    for node in tree:
        print(node.val)

if __name__ == '__main__':
    main()