def is_bst(node, lower_bound=float('-inf'), upper_bound=float('inf')):
    if not node:
        return True

    val = node.val
    if val <= lower_bound or val >= upper_bound:
        return False

    return all([
        is_bst(node.left, lower_bound, val),
        is_bst(node.right, val, upper_bound),
    ])

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def main():
    N = int(input().strip())
    nodes = [TreeNode(int(input().strip())) for _ in range(N)]

    for i in range(N):
        if nodes[i].left:
            nodes[i].left.parent = nodes[i]
        if nodes[i].right:
            nodes[i].right.parent = nodes[i]

    print('YES' if is_bst(nodes[0]) else 'NO')

if __name__ == '__main__':
    main()