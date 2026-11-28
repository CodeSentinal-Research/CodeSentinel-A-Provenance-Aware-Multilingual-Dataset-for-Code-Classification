def find_3_nodes(root, k):
    stack, node = [], root
    while stack:
        while node:
            stack.append(node)
            node = node.left
        node = stack.pop()
        if node.val and k - node.val in (set(stack) | {node.parent}):
            return True
        node = node.right
    return False


class Node:
    def __init__(self, val, left=None, right=None, parent=None):
        self.val = val
        self.left = left
        self.right = right
        self.parent = parent

def construct_tree(nodes):
    nodes = [(None, None, None, None)] + nodes
    parents = {name: (node, None) for name, node in nodes}
    roots = {node.val: node for node in nodes}
    for name, node in parents.items():
        if node[1] is not None:
            parents[node[1]][0].left = roots[node[0]]
        else:
            roots[node[0]] .parent = parents[name][0]
            roots[node[0]] .left = parents[name][0]
    for node in roots.values():
        if node.parent is None:
            return node

def main():
    N = int(input().strip())
    nodes = [Node(int(input().strip())) for _ in range(N)]
    for i in range(N - 1):
        nodes[i + 1].left = nodes[i]
        nodes[i + 1].right = nodes[i].parent
        nodes[i + 1].parent = nodes[i]
    K = int(input().strip())
    root = construct_tree(nodes)
    print('YES' if find_3_nodes(root, K) else 'NO')


if __name__ == "__main__":
    main()