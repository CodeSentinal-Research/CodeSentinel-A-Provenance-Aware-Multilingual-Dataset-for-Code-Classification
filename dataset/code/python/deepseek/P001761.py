class Node:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def construct_tree(nodes):
    index = 0
    if nodes[index] is None:
        return None
    node = Node(nodes[index])
    index += 1
    queue = [node]
    while index < len(nodes) and len(queue) > 0:
        current_node = queue.pop(0)
        if nodes[index] is not None:
            current_node.left = Node(nodes[index])
            queue.append(current_node.left)
            index += 1
        if nodes[index] is not None:
            current_node.right = Node(nodes[index])
            queue.append(current_node.right)
            index += 1
    return node

def max_sum_subtree(node):
    if node is None:
        return 0
    left_sum = max_sum_subtree(node.left)
    right_sum = max_sum_subtree(node.right)
    return max(node.val, node.val + max(0, left_sum), node.val + max(0, right_sum))

def main():
    N = int(input().strip())
    nodes = list(map(int, input().strip().split()))
    tree = construct_tree(nodes)
    print(max_sum_subtree(tree))

if __name__ == "__main__":
    main()