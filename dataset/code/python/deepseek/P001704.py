def check_isomorphic(tree1, tree2):
    def dfs(node1, node2):
        if node1 is None and node2 is None:
            return True
        elif node1 is None or node2 is None:
            return False

        return (node1.val == node2.val and
                dfs(node1.left, node2.left) and
                dfs(node1.right, node2.right))

    return dfs(tree1, tree2)


class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None


def create_tree(nodes):
    node_map = {nodes[i]['val']: Node(nodes[i]['val']) for i in range(len(nodes))}

    for node, left_val in enumerate(nodes):
        if left_val in node_map:
            if nodes[left_val]['left'] is not None:
                node_map[left_val].left = node_map[nodes[left_val]['left']]
            if nodes[left_val]['right'] is not None:
                node_map[left_val].right = node_map[nodes[left_val]['right']]

    return node_map[nodes[0]['val']]


def main():
    N1 = int(input().strip())
    tree1_nodes = [dict(val=i, left=tree1_left, right=tree1_right)
                   for i in range(N1) for tree1_left in input().split() if tree1_left != '-' else None]
    tree1 = create_tree(tree1_nodes)

    N2 = int(input().strip())
    tree2_nodes = [dict(val=i, left=tree2_left, right=tree2_right)
                   for i in range(N2) for tree2_left in input().split() if tree2_left != '-' else None]
    tree2 = create_tree(tree2_nodes)

    print('YES' if check_isomorphic(tree1, tree2) else 'NO')


if __name__ == '__main__':
    main()