class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def build_tree(nodes):
    root = None
    nodes_by_id = {id(node): node for node in nodes}
    for node_id, details in enumerate(nodes):
        left, right = details[1:-1]
        if left != '$':
            node_left = nodes_by_id[left]
        else:
            node_left = None
        if right != '$':
            node_right = nodes_by_id[right]
        else:
            node_right = None
        node = Node(details[0])
        if node_id == nodes[-1][0] - nodes[-1][1]:
            root = node
        if left != '$':
            node.left = node_left
        if right != '$':
            node.right = node_right
        nodes_by_id[details[0]] = node
    return root

def find_longest_path(root):
    if not root:
        return 0
    left_path = find_longest_path(root.left)
    right_path = find_longest_path(root.right)
    longest_path = max(left_path, right_path, left_path + right_path + 1)
    return longest_path

def main():
    N = int(input())
    nodes = list(input().split())
    root = build_tree(nodes)
    print(find_longest_path(root))

if __name__ == "__main__":
    main()